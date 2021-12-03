EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F4:STM32F411VETx U?
U 1 1 61A98268
P 5250 4200
F 0 "U?" H 5250 1411 50  0000 C CNN
F 1 "STM32F411VETx" H 5250 1320 50  0000 C CNN
F 2 "Package_QFP:LQFP-100_14x14mm_P0.5mm" H 4550 1700 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00115249.pdf" H 5250 4200 50  0001 C CNN
	1    5250 4200
	1    0    0    -1  
$EndComp
Text Notes 7150 7000 0    276  ~ 0
Ethan Cinq-Mars\n
Text Notes 7350 7550 0    157  ~ 0
Hydrolab Schematic
Text Notes 10550 7650 0    138  ~ 0
1
Wire Wire Line
	6150 5050 6150 5100
Wire Wire Line
	4350 5100 3900 5100
Wire Wire Line
	4350 5200 3900 5200
Wire Wire Line
	4350 5300 3900 5300
Wire Wire Line
	4350 5400 3900 5400
Wire Wire Line
	4350 5500 3900 5500
Wire Wire Line
	4350 5600 3900 5600
Text Label 3900 5100 2    59   ~ 0
LCD_D7
Text Label 3900 5200 2    59   ~ 0
LCD_D6
Text Label 3900 5300 2    59   ~ 0
LCD_d5
Text Label 3900 5400 2    59   ~ 0
LCD_D4
Text Label 3900 5500 2    59   ~ 0
LCD_E
Text Label 3900 5600 2    59   ~ 0
LCD_RS
$EndSCHEMATC
