#include <Windows.h>

#include <chrono>
#include <ctime>
#include <iostream>
#include <tuple>
#include <typeinfo>

enum class LOG_TYPE {
  SUCCESS = 10,
  INFO = 3,
  WARNING = 6,
  ERR = 4,
  BUG = 14,
  CRITICAL_ERROR = 64
};

class KFCppLog {
 public:
  // Log message
  static void log(std::string logContent, LOG_TYPE logType) {
    printType(logType);
    printCurrentTime();
    std::cout << logContent << std::endl;
  }

  // Log message with variable
  template <class T>
  static void logVar(std::string logContent, LOG_TYPE logType, const T& t) {
    printType(logType);
    printCurrentTime();
    std::string type = typeid(t).name();
    if (type == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE") {
      type = "string";
    } else if (type == "i") {
      type = "int";
    } else if (type == "f") {
      type = "float";
    }
    // Add more in future
    std::cout << logContent << " [ value of '" << type << "' = '" << t << "' ]"
              << std::endl;
  }

  // Log messages with variables
  template <class... T>
  static void logVars(std::string logContent, LOG_TYPE logType, T... t) {
    (logVar(logContent, logType, t), ...);
  }

 private:
  // Print prefix of message with type of log
  static void printType(LOG_TYPE type) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)type);
    std::cout << "[ ";
    switch (type) {
      case LOG_TYPE::SUCCESS:
        std::cout << "OK";
        break;
      case LOG_TYPE::INFO:
        std::cout << "INFO";
        break;
      case LOG_TYPE::WARNING:
        std::cout << "WARN";
        break;
      case LOG_TYPE::ERR:
        std::cout << "ERROR";
        break;
      case LOG_TYPE::BUG:
        std::cout << "BUG";
        break;
      case LOG_TYPE::CRITICAL_ERROR:
        std::cout << "CRITICAL ERROR";
        break;
      default:
        std::cout << "UNKNOWN TYPE";
        exit(-1);
    }
    std::cout << " ]";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    std::cout << '\t';
  }

  // Get current time
  static void printCurrentTime() {
    auto timePoint = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
    std::string timeStr = std::ctime(&time);
    // Removes magic '\n'
    timeStr.pop_back();
    std::cout << "(" << timeStr << ")\t";
  }
};
