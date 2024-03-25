# Password Manager

Программа для хранения и управления паролями. Позволяет пользователю создавать новые пароли вручную или с помощью генератора, просматривать все сохраненные пароли и управлять ими.

## Установка

1. Склонируйте репозиторий:

    ```bash
    git clone https://github.com/vbncursed/pass-manager.git
    ```

2. Перейдите в директорию с проектом:

    ```bash
    cd password-manager
    ```

3. Соберите проект:

    ```bash
    g++ main.cpp password_manager.cpp -o password_manager
    ```

4. Запустите программу:

    ```bash
    ./password_manager
    ```

## Использование

При запуске программы откроется меню с возможными действиями:

1. **Создать пароль вручную**: Пользователь может ввести URL сайта, логин и пароль вручную.
2. **Создать пароль с помощью генератора**: Программа сгенерирует случайный пароль для указанного URL сайта и логина.
3. **Просмотреть все пароли**: Отображает список всех сохраненных паролей.
4. **Выход**: Завершает программу.

## Зависимости

- C++11
- Библиотека `<fstream>` для работы с файлами
- Библиотека `<unistd.h>` для работы с файловой системой
- Библиотека `<ctime>` для работы со временем
- Библиотека `<cstdlib>` для генерации случайных чисел

## Советы по безопасности

1. Никогда не храните важные пароли в открытом виде.
2. Регулярно обновляйте пароли.
3. Используйте разные пароли для разных сервисов.
4. Рассмотрите использование менеджера паролей для более безопасного хранения и управления паролями.

## Лицензия

Этот проект лицензирован под [MIT License](LICENSE).
