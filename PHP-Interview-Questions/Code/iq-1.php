<?php
$str1 = 'yabadabadoo';
$str2 = 'yaba';
if (strpos($str1,$str2) !== false) {
  echo "\"" . $str1 . "\" contains \"" . $str2 . "\"";
} else {
  echo "\"" . $str1 . "\" does not contain \"" . $str2 . "\"";
}
?>
