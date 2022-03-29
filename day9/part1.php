<?php
$handle = fopen("input", "r");
if (!$handle) {
    echo "error";
} 

$mat = array();
while (($line = fgets($handle)) !== false) {
    $numbers = preg_replace('/[^0-9]/', '', $line);
    $mat[] = $numbers;
}
fclose($handle);

$risk = 0;
for($i = 0; $i<=99; $i++){
    for($j = 0; $j<=99; $j++){
        $actual = $mat[$i][$j];
        $up = 11;
        $down = 11;
        $right = 11;
        $left = 11;
        if(($i - 1) >= 0){
            $up = $mat[$i-1][$j];
        }
        if(($j - 1) >= 0){
            $left = $mat[$i][$j-1];
        }
        if(($i + 1) <= 99){
            $right = $mat[$i+1][$j];
        }
        if(($j + 1) <= 99){
            $down = $mat[$i][$j+1];
        }
        if(($actual < $up) && ($actual < $down) && ($actual < $right) && ($actual < $left)){
            $risk += ($actual + 1);
        }
    }
}
echo "THE TOTL RISK IS: ".$risk;
