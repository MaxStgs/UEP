<h1>Установка плагинов</h1>
<h3>Game-only plugin</h3>
Мы устанавливаем плагин с именем PackOfFunctions, он поставляется в папке PackOfFunctions он открывает игровые возможности недоступные в редакторе.

1. В корне проекта, создаем папку plugins
2. Помещаем плагин в папку plugins
3. Открываем файл unigine.cfg в корень_проекта/bin
4. Делаем поиск строки "extern_plugin" либо создаем в конце строку <item name="extern_plugin" type="string">../plugins/PackOfFunctions/bin/PackOfFunctions</item>
В случае, если такая строка имеется, то перед </item> нужно поставить запятую и указать путь к плагину в виде ../plugins/PackOfFunctions/bin/PackOfFunctions
5. Сохраняем, закрываем файл.


<h3>Editor-only plugin</h3>
Другой плагин, возможности которого доступны только в редакторе с названием PackOfFunctions, поставляется в папке PackOfFunctions.

1. В корне проекта, создаем папку plugins
2. Помещаем плагин в папку plugins
3. Заходим в SDK Browser переходим к проекту
4. Под кнопкой Open Editor, есть кнопка с тремя точками - жмем по ней.
5. В появившемся окне в Additional arguments ищем -extern_plugin и перед следующим символом(не пробелом) пишем путь к плагину "../plugins/PackOfFunctions/bin/PackOfFunctions," не забудьте в конце запятую. В случае, если -extern_plugin нет - то пишем в конце строки " -extern_plugin ../plugins/PackOfFunctions/bin/PackOfFunctions"

<h3>Game&Editor plugin</h3>

1. В корне проекта, создаем папку plugins
2. Помещаем плагин в папку plugins
3. Открываем файл unigine.cfg в корень_проекта/bin
4. Делаем поиск строки "extern_plugin" либо создаем в конце строку <item name="extern_plugin" type="string">../plugins/PackOfFunctions/bin/PackOfFunctions</item>
В случае, если такая строка имеется, то перед </item> нужно поставить запятую и указать путь к плагину в виде ../plugins/PackOfFunctions/bin/PackOfFunctions
5. Сохраняем, закрываем файл.
6. Заходим в SDK Browser переходим к проекту
7. Под кнопкой Open Editor, есть кнопка с тремя точками - жмем по ней.
8. В появившемся окне в Additional arguments ищем -extern_plugin и перед следующим символом(не пробелом) пишем путь к плагину "../plugins/PackOfFunctions/bin/PackOfFunctions," не забудьте в конце запятую. В случае, если -extern_plugin нет - то пишем в конце строки " -extern_plugin ../plugins/PackOfFunctions/bin/PackOfFunctions"

<h1>Обновление плагина</h1>
Все плагины поставляются вместе с программой update.exe и файлом update.bat
В любой момент можно произвести принудительное обновление - посредством вызова update.bat
