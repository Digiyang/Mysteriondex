%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterl�sung - Aufgabe 9
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule f�r Technik Berlin
%--------------------------------------------------------------

clear
close all
home

% Eingabe der Widerst�nde in Ohm
R1 = 10e3;
R2 = 50;
R3 = 200;
R4 = 200;
R5 = 200;
R6 = 1;
U = 10;

% Exakte L�sung mit Matlab:
R_ges = 1/(1/R1+1/R2) + R3 + 1/(1/R4+1/R5) + R6;

I = U / R_ges * 1000  % Ausgabe in mA