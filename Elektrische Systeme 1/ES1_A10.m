%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 10
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

% Eingabe der Widerstände in Ohm
R1 = 1000;
R2 = 10;
R3 = 200;
R4 = 500;
R5 = R4;

G_345 = 1/R3 + 1/(R4+R5);
R_2345 = R2 + 1/G_345;
G_AB = 1/R1 + 1/R_2345;
R_AB = 1/G_AB

% Alternative Lösung mit Verwendung der Funktion p()
R_AB = p(R1, R2 + p(R3, R4+R5))
