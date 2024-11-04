#include <Manager/IconsMaterialDesign.h>
#include <Wizard/WizardManager.h>
#include <Wizard/WizardStage.h>

WizardManager::WizardManager(ILogger* logger)
{
    m_pLogger = logger;
}

WizardManager::~WizardManager()
{
}

void WizardManager::AddStage(WizardStage* pStage)
{
    if (m_State != EState::None)
        throw std::logic_error("Can't add stages now");

    Stage stage;
    stage.pStage = pStage;
    
    for (WizardStage* pDep : pStage->GetDependencies())
    {
        auto depIt = std::find_if(m_Stages.begin(), m_Stages.end(), [&](const Stage& x) { return x.pStage == pDep; });

        if (depIt == m_Stages.end())
            throw std::logic_error(fmt::format("Dependency '{}' not found", pDep->GetDisplayName()));

        stage.dependsOn.push_back(depIt - m_Stages.begin());
    }

    m_Stages.emplace_back(std::move(stage));
}

bool WizardManager::IsStageDone(WizardStage* pStage) const
{
    for (size_t i = 0; i < m_Stages.size(); i++)
    {
        if (m_Stages[i].pStage == pStage)
            return m_Stages[i].isDone || m_Stages[i].initialStatus;
    }

    return false;
}

bool WizardManager::UpdateNoDialog()
{
    Update();
    return IsDone();
}

bool WizardManager::ShowContent()
{
    Update();

    ImGuiStyle& style = ImGui::GetStyle();

    // Sidebar
    if (ImGui::BeginChild("Sidebar", ImVec2(10 * ImGui::GetFontSize(), 0)))
    {
        for (size_t i = 0; i < m_Stages.size(); i++)
        {
            Stage& stage = m_Stages[i];

            if (m_State != EState::InitialCheck && stage.initialStatus)
                continue;

            const char* displayName = stage.pStage->GetDisplayName().c_str();
                
            if (m_State != EState::InitialCheck)
            {
                if ((int)i == GetCurrentStageIdx())
                    ImGui::TextUnformatted(ICON_MD_CHEVRON_RIGHT);
                else if (stage.isDone)
                    ImGui::TextUnformatted(ICON_MD_CHECK);
                else
                    ImGui::TextUnformatted(ICON_MD_REMOVE);
            }
            else
            {
                ImGui::TextUnformatted(ICON_MD_REMOVE);
            }

            ImGui::SameLine();
            ImGui::SetCursorPosX(1.3f * ImGui::GetFontSize());
            ImGui::TextUnformatted(displayName);
        }
    }

    ImGui::EndChild();
    ImGui::SameLine();

    if (ImGui::BeginChild("Content"))
    {
        float offsetFromBottom = ImGui::GetFontSize() + 2 * style.FramePadding.y + style.ItemSpacing.y;
        bool canCancel = false;
        bool canPrev = false;
        bool canNext = false;

        if (ImGui::BeginChild("Stage", ImVec2(0, ImGui::GetContentRegionAvail().y - offsetFromBottom)))
        {
            switch (m_State)
            {
            case EState::None:
            {
                break;
            }
            case EState::InitialCheck:
            {
                ImGui::Text(m_InitialCheckText.c_str());
                break;
            }
            case EState::Wizard:
            {
                m_Stages[GetCurrentStageIdx()].pStage->ShowContent();
                break;
            }
            case EState::CheckingCurrentResult:
            {
                ImGui::Text("Validating...");
                break;
            }
            }
        }

        ImGui::EndChild();

        if (ImGui::BeginChild("Buttons"))
        {
            switch (m_State)
            {
            case EState::Wizard:
            {
                Stage& stage = m_Stages[GetCurrentStageIdx()];

                ImGui::BeginDisabled(!stage.pStage->CanCancel());
                ImGui::Button("Cancel");
                ImGui::EndDisabled();

                ImGui::SameLine();

                ImGui::BeginDisabled(m_CurrentVisibleIdx == 0 || !stage.pStage->CanCancel() || !m_Stages[m_VisibleStages[m_CurrentVisibleIdx - 1]].pStage->CanReturn());
                if (ImGui::Button("< Prev"))
                    GoToPrev();
                ImGui::EndDisabled();

                ImGui::SameLine();

                if (m_CurrentVisibleIdx == (int)m_VisibleStages.size() - 1)
                {
                    if (ImGui::Button("Finish >"))
                        Finish();
                }
                else
                {
                    ImGui::BeginDisabled(!stage.pStage->CanContinue());
                    if (ImGui::Button("Next >"))
                        GoToNext();
                    ImGui::EndDisabled();
                }

                break;
            }
            default:
            {
                ImGui::Button("Cancel");
                ImGui::SameLine();
                ImGui::Button("< Prev");
                ImGui::SameLine();
                ImGui::Button("Next >");
                break;
            }
            }
        }

        ImGui::EndChild();
    }

    ImGui::EndChild();

    return IsDone();
}

void WizardManager::Update()
{
    switch (m_State)
    {
    case EState::None:
    {
        // Begin the initial check
        m_InitialCheckFuture = InitialCheckAsync();
        m_State = EState::InitialCheck;
        break;
    }
    case EState::InitialCheck:
    {
        // Check if check is done
        if (IsFutureReady(m_InitialCheckFuture))
        {
            m_InitialCheckFuture.get();
            m_VisibleStages.clear();

            // Build a list of unfinished stages
            for (size_t i = 0; i < m_Stages.size(); i++)
            {
                if (!m_Stages[i].initialStatus)
                {
                    m_VisibleStages.push_back((int)i);
                }
            }

            if (m_VisibleStages.empty())
            {
                // Done
                m_State = EState::Done;
            }
            else
            {
                // Run the wizard
                m_State = EState::Wizard;
                m_CurrentVisibleIdx = 0;
                m_Stages[GetCurrentStageIdx()].pStage->OnActive();
            }
        }

        break;
    }
    case EState::Wizard:
    {
        m_Stages[GetCurrentStageIdx()].pStage->Update();
        break;
    }
    case EState::CheckingCurrentResult:
    {
        if (IsFutureReady(m_CurrentCheckFuture))
        {
            OnCurrentCheckFinished();
        }

        break;
    }
    case EState::Done:
    {
        break;
    }
    }
}

void WizardManager::GoToNext()
{
    Stage& stage = m_Stages[GetCurrentStageIdx()];

    if (m_CurrentVisibleIdx == (int)m_VisibleStages.size() - 1 || !stage.pStage->CanContinue())
        return;

    if (!stage.pStage->TryContinue())
        return;

    // Check whether current stage has succeded
    m_State = EState::CheckingCurrentResult;
    m_CurrentCheckFuture = CurrentCheckAsync();

    // Block a bit to not show the placeholder screen
    if (m_CurrentCheckFuture.wait_for(std::chrono::milliseconds(100)) == std::future_status::ready)
    {
        OnCurrentCheckFinished();
    }
}

void WizardManager::GoToPrev()
{
    Stage& stage = m_Stages[GetCurrentStageIdx()];

    if (m_CurrentVisibleIdx == 0 || !stage.pStage->CanCancel() || !m_Stages[m_VisibleStages[m_CurrentVisibleIdx - 1]].pStage->CanReturn())
        return;

    if (!stage.pStage->TryCancel())
        return;

    m_Stages[GetCurrentStageIdx()].pStage->OnInactive();
    m_CurrentVisibleIdx--;

    m_Stages[GetCurrentStageIdx()].isDone = false;
    m_Stages[GetCurrentStageIdx()].pStage->OnActive();
}

void WizardManager::Finish()
{
    m_State = EState::Done;
}

void WizardManager::OnCurrentCheckFinished()
{
    bool succeded = false;

    try
    {
        succeded = m_CurrentCheckFuture.get();
    }
    catch (const std::exception& e)
    {
        m_pLogger->Log(severityLevel::error, "[Wizard] %s: failed with exception %s", m_Stages[GetCurrentStageIdx()].pStage->GetDisplayName(), e.what());
        succeded = false;
    }

    m_State = EState::Wizard;
    m_Stages[GetCurrentStageIdx()].isDone = succeded;

    if (succeded)
    {
        m_Stages[GetCurrentStageIdx()].pStage->OnInactive();
        m_CurrentVisibleIdx++;
        m_Stages[GetCurrentStageIdx()].pStage->OnActive();
    }
}

std::future<void> WizardManager::InitialCheckAsync()
{
    return std::async(std::launch::async, [=]()
    {
        for (Stage& stage : m_Stages)
        {
            // Check dependencies
            bool allDepsReady = true;

            for (size_t depIdx : stage.dependsOn)
            {
                if (!m_Stages[depIdx].initialStatus)
                {
                    allDepsReady = false;
                    break;
                }
            }

            if (!allDepsReady)
                continue;

            // Check the conditions
            try
            {
                bool isFinished = stage.pStage->CheckFinishedConditionAsync(true).get();
                stage.initialStatus = isFinished;
                m_pLogger->Log(severityLevel::debug, "[Wizard] %s: initial status %d", stage.pStage->GetDisplayName(), isFinished);
            }
            catch (const std::exception& e)
            {
                m_pLogger->Log(severityLevel::error, "[Wizard] %s: failed with exception %s", stage.pStage->GetDisplayName(), e.what());
                stage.initialStatus = false;
            }
        }
    });
}

std::future<bool> WizardManager::CurrentCheckAsync()
{
    return m_Stages[GetCurrentStageIdx()].pStage->CheckFinishedConditionAsync(false);
}
