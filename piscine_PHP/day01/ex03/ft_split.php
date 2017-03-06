<?php

function ft_split($str)
{
    $tab = explode(" ", $str);
    $tab = array_filter($tab);
    $final = array_slice($tab, 0);
    sort($final);
    return ($final);
}
?>