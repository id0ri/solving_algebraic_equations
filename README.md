# Решение нелинейных алгебраических уравнений
  
## Структура проекта  
  
solving_algebraic_equations/  
├── solver_cpp.cpp  
      ├── main.cpp  
├── README.md  
└── .gitignore  
  
## Описание задачи
  
Программа реализует три численных метода решения нелинейных алгебраических уравнений вида  
**f(x) = 0**:
  
- **Метод Ньютона**  
- **Метод парабол**  
- **Метод обратной параболы**  
  
Все три метода реализованы в одном файле с подробным выводом каждой итерации.  
  
Пример уравнения по умолчанию:  
  
```cpp  
f(x) = x^3 - 2x - 5 = 0  
```  
  
  
# Установка репозитория  
  
Перед запуском убедитесь, что у вас установлен компилятор C++ с поддержкой стандарта C++17:  
На linux: g++ / clang++
На windows: MinGW-w64 / Visual Studio
  
## Скачивание кода
  
git clone https://github.com/id0ri/solving_algebraic_equations.git  
cd solving_algebraic_equations/solver_cpp  
  
## Запуск программы
  
В Windows Visual Studio:  
- Создаем новое решение  
- Копируем код из solver_cpp/main.cpp в созданный проект  
- Запускаем проект  
  
В Linux:  
- g++ main.cpp -o solver  
- chmod +x solver  
- ./solver  