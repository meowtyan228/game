#ifndef ERROR
#define ERROR

enum ERROR
{
   OUT_OF_BOUNDS = 1 ,           // Координаты вне границ поля
   SIZE_TOO_LARGE,          // Размер корабля превышает границы поля
   CELL_NOT_EMPTY,          // Ячейка уже занята
   SURROUNDING_CHECK_FAILED, // Проверка соседних ячеек не пройдена
   INCORRECT_ORIENTATION
   
};

#endif