# КДЗ-2: ratexpr
Библиотека рациональных чисел и выражений на C++ 17

## Требования
- CMake 3.10 и новее
- Компилятор с поддержкой С++17

## Сброка
Debug
```
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug && cmake --build build-debug -j
```
Release
```
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release && cmake --build build-release -j
```

## Запуск
 
Linux и MacOS:
```
./build-debug/apps/demo_fraction
./build-debug/apps/demo_expression
```

```
./build-release/apps/demo_fraction
./build-release/apps/demo_expression
```

Windows:

```
.\build-debug\apps\demo_fraction.exe
.\build-debug\apps\demo_expression.exe
```

```
.\build-release\apps\demo_fraction.exe
..\build-release\apps\demo_expression.exe
```