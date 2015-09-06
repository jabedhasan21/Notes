<?php

$games = ['efect','jabed','hasan','bangali','babu'];

//sort($games);
//rsort($games);
usort($games, function($a,$b) {
  var_dump('a:'.$a.', b:'.$b);
  //return $a <=> $b; // -1,0,1
  //return strlen($a) <=> strlen($b);
  return strlen($b) <=> strlen($a);
});
var_dump($games);
