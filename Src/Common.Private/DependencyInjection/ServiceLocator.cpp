//
// Created by theli on 5/7/2025.
//

#include "ServiceLocator.h"

std::unique_ptr<IChairServiceProvider> ServiceLocator::provider_;
std::mutex ServiceLocator::mutex_;
