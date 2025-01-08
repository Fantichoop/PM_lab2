#ifndef MINI_MINI_HAL_H
#define MINI_MINI_HAL_H

#include <Arduino.h>

// Типы данных с аттрибутами, определяющими использование различных режимов для чисел.
typedef signed int Int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int Uint8_t __attribute__((__mode__(__QI__)));
typedef signed int Int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int Uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int Int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int Uint32_t __attribute__ ((__mode__ (__SI__)));

// Макрос для сброса бита в регистре.
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))

// Класс Mini_mini_HAL предоставляет интерфейс для работы с пинами на микроконтроллере.
class Mini_mini_HAL
{
public:
    Mini_mini_HAL();  // Конструктор класса
    void DigitalWrite(uint8_t pin, uint8_t val);  // Запись значения в цифровой пин
    void PinMode(uint8_t pin, uint8_t mode);  // Установка режима пина
    int DigitalRead(uint8_t pin);  // Чтение значения с цифрового пина
    static void TurnOffPWM(uint8_t timer);  // Отключение ШИМ на пине
    void Delay(unsigned long ms);  // Задержка
    volatile Uint8_t * PortOutputRegister(Uint8_t P);  // Получение регистра вывода для порта
    Uint8_t DigitalPinToTimer(Uint8_t P);  // Получение таймера для пина
    Uint8_t DigitalPinToBitMask(Uint8_t P);  // Получение битовой маски для пина
    Uint8_t DigitalPinToPort(Uint8_t P);  // Получение порта для пина
private:

};

#endif