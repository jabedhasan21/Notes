<?php
  $a = '1';
  $b = &$a;
  $b = "2$b";
  echo 'a:'.$a;
  echo '<br/>';
  echo 'b:'.$b;
 ?>
