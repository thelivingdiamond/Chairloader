function AssignPFPropertiesToPathType(...)
  AI.AssignPFPropertiesToPathType(...)
  if System.IsEditor() and EditorAI then
    EditorAI.AssignPFPropertiesToPathType(...)
  end
end
AssignPFPropertiesToPathType("AIPATH_HUMAN", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_SMARTOBJECT, 0, 0, 0, 0, 0, 5, 0.5, -10000, 0, 20, 3.5, 0, 0.4, 2, 45, 1, true)
AI.AssignPathTypeToSOUser("Human", "AIPATH_HUMAN")
AssignPFPropertiesToPathType("AIPATH_CAR", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_ROAD, 18, 18, 0, 0, 0, 0, 1.5, -10000, 0, 0, 7, 0, 0.3, 2, 0, 5, true)
AssignPFPropertiesToPathType("AIPATH_TANK", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_ROAD, 18, 18, 0, 0, 0, 0, 1.5, -10000, 0, 0, 7, 0, 0.3, 2, 0, 6, true)
AssignPFPropertiesToPathType("AIPATH_DEFAULT", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_SMARTOBJECT, 0, 0, 0, 0, 0, 5, 0.5, -10000, 0, 20, 3.5, 0, 0.4, 2, 45, 7, true)
AssignPFPropertiesToPathType("AIPATH_MIMIC", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_SMARTOBJECT, 0, 0, 0, 0, 0, 5, 0.5, -10000, 0, 20, 3.5, 0, 0.4, 1, 45, 1, true)
AssignPFPropertiesToPathType("AIPATH_PHANTOM", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_SMARTOBJECT, 0, 0, 0, 0, 0, 5, 0.5, -10000, 0, 20, 3.5, 0, 0.625, 2.35, 45, 1, true)
AssignPFPropertiesToPathType("AIPATH_OPERATOR", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_SMARTOBJECT, 0, 0, 0, 0, 0, 5, 0.5, -10000, 0, 20, 3.5, 0, 0.6, 2, 45, 1, true)
AssignPFPropertiesToPathType("AIPATH_OVERSEER", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_SMARTOBJECT, 0, 0, 0, 0, 0, 5, 0.5, -10000, 0, 20, 3.5, 0, 1, 2, 45, 1, true)
AssignPFPropertiesToPathType("AIPATH_NIGHTMARE", NAV_TRIANGULAR + NAV_WAYPOINT_HUMAN + NAV_SMARTOBJECT, 0, 0, 0, 0, 0, 5, 0.5, -10000, 0, 20, 3.5, 0, 3, 4, 45, 1, true, 0.65, 0.2)
AI.AssignPathTypeToSOUser("ArkAlien", "AIPATH_PHANTOM")
AI.AssignPathTypeToSOUser("ArkBeta", "AIPATH_PHANTOM")
AI.AssignPathTypeToSOUser("ArkMimic", "AIPATH_MIMIC")
