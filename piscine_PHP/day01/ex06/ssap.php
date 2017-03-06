#! /usr/bin/php
<?php

$i = 0;
foreach ($argv as $elem)
{
    if ($i == 0)
        $i = 1;
    else
    {
        if (!$str)
            $str = $elem;
        else
            $str = "$str $elem";
    }
}
$str = preg_replace("#[ ]+#", " ", $str);
$tab = explode(" ", $str);
sort($tab);
foreach ($tab as $elem)
    echo $elem."\n";

?>