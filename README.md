# 1C_task141

Очевидное решение данной задачи забрутфорсить и определить сходимость.
Но помимо сложности алгоритма требуются какие-то огромные вычислительные мощности. Поэтому пойдем от обратного. 
Обычно такие задачи приходится решать онлайн карточным играм, чтобы игрокам не попадались слишком часто нерешаемые случаи. 
Поэтому  была предпринята попытка проверить расклад до брутфорса на какие-то необхадимые минимальные условия.
Минимальное необходимое для успеха чтобы один туз находился в самом низу на исходной позиции иначе мы никак не сможем его передвинуть.
Проверяем на это а затем проверяем не закрыты ли хотя бы один тип карт другим тузом сверху.
То есть если все 7 лежат под тузами очевидно мы не сможем ничего с ними сделать.
И последнее проверяем сможем ли мы докапаться до нашего туза стоящего на правильном месте.
Если хотя бы одно условие не выполненно смысла проверять проверку нет.
Если же они выполнены то мы должны переставить следующий туз на освободившееся место и повторить дейтсвия
 
