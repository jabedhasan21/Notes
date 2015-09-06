<?php

//$_GET['name'] = 'jabed';

# The Null Coalesce Operator

//$name = isset($_GET['name'])? $_GET['name'] :'nothing';

// New in php 7
$name = $_GET['name'] ?? 'nothing';

var_dump($name);

// Other Example
echo $name2 ?? 'Jabed Bangali';
