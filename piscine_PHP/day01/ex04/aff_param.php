#! /usr/bin/php
<?php

$count = 0;
foreach ($argv as $elem)
{
    if ($count == 0)
        $count = 1;
    else
        echo $elem."\n";
}

?>