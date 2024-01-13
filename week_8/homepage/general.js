var home = document.querySelector('.home a');
home.addEventListener('mouseover', function() {
    home.style.backgroundColor = 'rgba(128, 128, 128, 0.2)';
    home.style.borderRadius = '2px';
    home.style.color = 'white';
});
home.addEventListener('mouseout', function() {
    home.style.backgroundColor = 'transparent'
})

var about = document.querySelector('.about-me a');
about.addEventListener('mouseover', function() {
    about.style.backgroundColor = 'rgba(128, 128, 128, 0.2)';
    about.style.borderRadius = '2px';
    about.style.color = 'white';
});
about.addEventListener('mouseout', function() {
    about.style.backgroundColor = 'transparent'
})

var experience = document.querySelector('.experience a');
experience.addEventListener('mouseover', function() {
    experience.style.backgroundColor = 'rgba(128, 128, 128, 0.2)';
    experience.style.borderRadius = '2px';
    experience.style.color = 'white';
});
experience.addEventListener('mouseout', function() {
    experience.style.backgroundColor = 'transparent'
})

var contact = document.querySelector('.contact a');
contact.addEventListener('mouseover', function() {
    contact.style.backgroundColor = 'rgba(128, 128, 128, 0.2)';
    contact.style.borderRadius = '2px';
    contact.style.color = 'white';

});
contact.addEventListener('mouseout', function() {
    contact.style.backgroundColor = 'transparent'
})