find_package(Boost REQUIRED
  COMPONENTS
    chrono
    system
    thread
)
list(APPEND pluginlib_LIBRARIES ${Boost_LIBRARIES})
