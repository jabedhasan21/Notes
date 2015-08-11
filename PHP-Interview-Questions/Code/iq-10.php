<?php
    $arr = array(
    	'0' => 'z1',
    	'1' => 'Z10',
    	'2' => 'z12',
    	'3' => 'Z2',
    	'4' => 'z3',
    );

    asort($arr,SORT_STRING|SORT_FLAG_CASE|SORT_NATURAL);
    var_dump($arr);
 ?>
