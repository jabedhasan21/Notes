<?php
declare(strict_types =1);

// function setAge
function setAge(int $age) {
  var_dump($age);
}
//setAge('jabed');
//setAge(26);
//setAge('26');

// function setIsValid
function setIsValid(bool $value) {
  var_dump($value);
}
//setIsValid(true);
//setIsValid(1);
//setIsValid(0);
setIsValid(-1);
//setIsValid('jabed');
//setIsValid([]);
