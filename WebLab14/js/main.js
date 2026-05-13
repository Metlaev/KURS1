import '../css/style.css'

function saveData(event) {
    const element = event.target;
    if (element.id) {
        localStorage.setItem('cv_data_' + element.id, element.innerText);
    }
}

function loadData() {
    // находим все элементы с атрибутом contenteditable
    const editableElements = document.querySelectorAll('[contenteditable="true"]');
    
    editableElements.forEach(el => {
        // проверяем, есть ли сохраненный текст для этого ID
        const savedText = localStorage.getItem('cv_data_' + el);
        if (savedText) {
            el.innerText = savedText;
        }

        // вешаем событие "input" (срабатывает при каждом изменении текста)
        el.addEventListener('input', saveData);
    });
}
document.querySelectorAll('.card').forEach(card => {
    card.addEventListener('mousedown', function(e) {
        const ripple = document.createElement('span');
        ripple.classList.add('ripple');
        this.appendChild(ripple);

        // Получаем точные координаты карточки на странице
        const rect = this.getBoundingClientRect();
        
        // Вычисляем координаты клика относительно карточки, а не текста внутри
        const x = e.clientX - rect.left;
        const y = e.clientY - rect.top;

        ripple.style.left = `${x}px`;
        ripple.style.top = `${y}px`;

        // Удаляем элемент после завершения анимации
        ripple.addEventListener('animationend', () => {
            ripple.remove();
        });
    });
});

document.getElementById('download-pdf').addEventListener('click', () => {
    window.print();
});

// Запускаем загрузку при старте страницы
loadData();