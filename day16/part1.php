<?php

function hexToBin($hexdec)
{
    $i = 0;
    $st = "";
    while ($i <= strlen($hexdec)-1)
    {
        switch ($hexdec[$i])
        {
        case '0':
            $st .= "0000";
            break;
        case '1':
            $st .= "0001";
            break;
        case '2':
            $st .= "0010";
            break;
        case '3':
            $st .= "0011";
            break;
        case '4':
            $st .= "0100";
            break;
        case '5':
            $st .= "1010";
            break;
        case '6':
            $st .= "0110";
            break;
        case '7':
            $st .= "0111";
            break;
        case '8':
            $st .= "1000";
            break;
        case '9':
            $st .= "1001";
            break;
        case 'A':
        case 'a':
            $st .= "1010";
            break;
        case 'B':
        case 'b':
            $st .= "1011";
            break;
        case 'C':
        case 'c':
            $st .= "1100";
            break;
        case 'D':
        case 'd':
            $st .= "1101";
            break;
        case 'E':
        case 'e':
            $st .= "1110";
            break;
        case 'F':
        case 'f':
            $st .= "1111";
            break;
        default:
            echo "\nInvalid hexadecimal digit ".
                                    $hexdec[$i];
                                    break;
        }
        $i++;
    }
    return $st;
}
 
echo "hello world!\n";

$file = fopen("input", "r") or die("Unable to open file!");
$hex = fread($file,filesize("input"));
fclose($file);

echo $hex."\n";
$binary = hexToBin($hex);
echo $binary;

$versions = 0;
$j = 0;
while($j <= strlen($binary)-1){

    
    $j++;    
}

?>