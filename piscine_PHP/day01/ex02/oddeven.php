#! /usr/bin/php
<?php

while ("$tmp" !== false && !feof(STDIN)){
    echo "Entrez un nombre: ";
    $tmp = fgets(STDIN);
    $tmp = trim($tmp);

    if (feof(STDIN)){
        echo "\n";
        break;
    }
    if (is_numeric($tmp)){
        if ($tmp % 2 == 1)
            echo "Le chiffre $tmp est Impair\n";
        if ($tmp % 2 == 0)
            echo "Le chiffre $tmp est Pair\n";
    }
    elseif (!is_numeric($tmp)){
        echo "'$tmp' n'est pas un chiffre\n";
    }
}

?>

