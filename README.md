# KFCppLog

## Simple, header-only c++ logging library

### Syntax

#### Simple log:

##### `logContent` -> message

##### `logType` -> type of log

```cpp
static void log(std::string logContent, LOG_TYPE logType);
```

#### Log with variable:

##### `logContent` -> message

##### `logType` -> type of log

##### `t` -> any variable which can be converted to string

```cpp
static void logVar(std::string logContent, LOG_TYPE logType, const T& t);
```

#### Log with multiple variable:

##### `logContent` -> message

##### `logType` -> type of log

##### `... t` -> variables which can be converted to string separated by comma ( , )

```cpp
static void logVars(std::string logContent, LOG_TYPE logType, T... t);
```

### Log types

##### `LOG_TYPE::SUCCESS `

##### `LOG_TYPE::INFO `

##### `LOG_TYPE::WARNING `

##### `LOG_TYPE::ERR `

##### `LOG_TYPE::BUG `

##### `LOG_TYPE::CRITICAL_ERROR `

### Example

```cpp
  int age = 24;
  std::string name = "Adam";

  int var1 = 123;
  float var2 = 123.456;
  std::string var3 = "123456789";

  KFCppLog::log("This is message", LOG_TYPE::WARNING);
  KFCppLog::logVar("Name log", LOG_TYPE::ERR, name);
  KFCppLog::logVar("Age log", LOG_TYPE::SUCCESS, age);
  KFCppLog::logVars("Age log", LOG_TYPE::INFO, var1, var2, var3);
```
