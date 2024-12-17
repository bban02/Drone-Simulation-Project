#include <DataSingleton.h>

int i = 0;  // tracker NEEDS TO BE DELETED

DataSingleton::DataSingleton() {}

DataSingleton::~DataSingleton() {}

DataSingleton* DataSingleton::instance = nullptr;

DataSingleton* DataSingleton::getInstance(Robot* entity) {
  if (instance == nullptr) {
    instance = new DataSingleton();
  }
  // business logic
  instance->locationData(entity);
  instance->premiumData(entity);
  instance->strategyData(entity);
  instance->ExportCsv();
  //
  ////TEST////
  std::cout << "premuim use " << instance->getPremuimUsage() << std::endl;
  std::cout << "prem amount " << instance->getPremuimAmount() << std::endl;
  std::cout << "norm use " << instance->getDroneUsage() << std::endl;
  std::cout << "vector: " << instance->allLocations[i].x << " "
            << instance->allLocations[i].y << " " << instance->allLocations[i].z
            << std::endl;
  i++;
  /////TEST/////
  return instance;
}

void DataSingleton::locationData(Robot* robot) {
  // collects data locations and stores them in a vector
  allLocations.push_back(robot->getPosition());
}

void DataSingleton::premiumData(Robot* robot) {
  // checks if premuim was used and adds it premiumUsage and premiumAmount
  // in simulation make loop to pass every entity into the singleton
  if (robot->getPackage()) {
    Package* newPackage = robot->getPackage();
    std::cout << "bool value " << newPackage->speedyDelivery
              << std::endl;  // NEEDS TO BE DELETED
    if ((newPackage->speedyDelivery) == true) {
      premiumUsage++;
      premiumAmount += 10;  // if we change cost this needs to be changed
    } else {
      droneUsage++;
    }
  }
}

void DataSingleton::strategyData(Robot* robot) {
  // collects all the strategies used and added to relative sum variable
  if (robot->getPackage()) {
    Package* newPackage = robot->getPackage();
    std::cout << "PACKAGE NAME " << newPackage->getStrategyName() << std::endl;
    if (newPackage->speedyDelivery) {
      sumBeeline++;
    } else {
      if ((newPackage->getStrategyName()) == "astar") {
        std::cout << "TEST1" << std::endl;
        sumAstar++;
      }
      if ((newPackage->getStrategyName()) == "dfs") {
        std::cout << "TEST2" << std::endl;
        sumDfs++;
      }
      if ((newPackage->getStrategyName()) == "bfs") {
        std::cout << "TEST3" << std::endl;
        sumBfs++;
      }
      if ((newPackage->getStrategyName()) == "dijkstra") {
        std::cout << "TEST4" << std::endl;
        sumDijkstra++;
      }
    }
  }
}

int DataSingleton::getPremuimUsage() { return premiumUsage; }

int DataSingleton::getDroneUsage() { return droneUsage; }

int DataSingleton::getPremuimAmount() { return premiumAmount; }

int DataSingleton::getAstar() { return sumAstar; }

int DataSingleton::getBeeline() { return sumBeeline; }
int DataSingleton::getBfs() { return sumBfs; }
int DataSingleton::getDijkstra() { return sumDijkstra; }

void DataSingleton::ExportCsv() {
  // exports the CSV
  std::ofstream file("Singleton.csv", std::ios::app);  // opened in append mode

  // open file
  if (file.is_open() != true) {
    std::cout << "ERROR: unable to open" << std::endl;
  }

  // location, total premium used, total revenue, total drone usage,
  // AstarAmount, Beeline, Bfs, Dijkstra, DFS
  file << instance->allLocations[i].x << " " << instance->allLocations[i].y
       << " " << instance->allLocations[i].z << ", ";
  file << premiumUsage << ", ";
  file << premiumAmount << ", ";
  file << droneUsage << ", ";
  file << sumAstar << ", ";
  file << sumBeeline << ", ";
  file << sumBfs << ", ";
  file << sumDijkstra << ", ";
  file << sumDfs;
  file << "\n";

  file.close();
}