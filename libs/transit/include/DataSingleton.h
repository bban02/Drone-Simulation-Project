#ifndef DATASINGLETON_H_
#define DATASINGLETON_H_

#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>  //might need to be something else

#include "IEntity.h"
#include "IStrategy.h"
#include "Package.h"
#include "Robot.h"
#include "math/vector3.h"

/**
 * @class DataSingleton
 * @brief Singleton class for collecting and exporting simulation data.
 */
class DataSingleton {
 public:
  /**
   * @brief Destructor for DataSingleton.
   */
  ~DataSingleton();

  /**
   * @brief Gets the instance of the DataSingleton.
   * @param entity Pointer to the Robot entity.
   * @return The instance of the DataSingleton.
   */
  static DataSingleton* getInstance(Robot* entity);

  /**
   * @brief Collects location data from a Robot entity.
   * @param robot Pointer to the Robot entity.
   */
  void locationData(Robot* robot);

  /**
   * @brief Collects premium data from a Robot entity.
   * @param robot Pointer to the Robot entity.
   */
  void premiumData(Robot* robot);

  /**
   * @brief Collects strategy data from a Robot entity.
   * @param robot Pointer to the Robot entity.
   */
  void strategyData(Robot* robot);

  /**
   * @brief Gets the total premium usage.
   * @return Total premium usage.
   */
  int getPremuimUsage();

  /**
   * @brief Gets the total drone usage.
   * @return Total drone usage.
   */
  int getDroneUsage();

  /**
   * @brief Gets the total premium amount.
   * @return Total premium amount.
   */
  int getPremuimAmount();

  /**
   * @brief Gets the count of Astar strategy usage.
   * @return Count of Astar strategy usage.
   */
  int getAstar();

  /**
   * @brief Gets the count of Beeline strategy usage.
   * @return Count of Beeline strategy usage.
   */
  int getBeeline();

  /**
   * @brief Gets the count of BFS strategy usage.
   * @return Count of BFS strategy usage.
   */
  int getBfs();

  /**
   * @brief Gets the count of Dijkstra strategy usage.
   * @return Count of Dijkstra strategy usage.
   */
  int getDijkstra();

  /**
   * @brief Exports data to a CSV file.
   */
  void ExportCsv();

 private:
  /**
   * @brief Constructor for DataSingleton.
   */
  DataSingleton();

  /**
   * @brief Copy constructor is deleted.
   */
  DataSingleton(const DataSingleton&) = delete;

  /**
   * @brief Copy assignment operator is deleted.
   */
  DataSingleton& operator=(const DataSingleton&) = delete;

  static DataSingleton* instance;

  std::vector<Vector3> allLocations;
  int premiumUsage = 0;
  int droneUsage = 0;
  float premiumAmount = 0.0;
  int sumAstar = 0;
  int sumBeeline = 0;
  int sumBfs = 0;
  int sumDijkstra = 0;
  int sumDfs = 0;
};

#endif