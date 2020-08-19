%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 27
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

f = 50;
U0 = 50;
om = 2*pi*f;
R1 = 200;
R = 10;
C = 5.0e-6;
L = 40.0e-3;

% Komplexe Widerstände
Z_RL = R + j*om*L; 
Z_C = 1/(j*om*C);
Z_RLC = 1/(1/Z_C + 1/Z_RL);
Z_ges = R1 + Z_RLC;

% Berechnung und Ausgabe von I1, I2 und I3 in A
I1 = U0/Z_ges;
I2 = I1 * Z_RL/(Z_RL+Z_C);
I3 = I1 - I2;
disp(['I1 = ',num2str(abs(I1)),' * exp(j* ', num2str(angle(I1)*180/pi), '°)']);
disp(['I2 = ',num2str(abs(I2)),' * exp(j* ', num2str(angle(I2)*180/pi), '°)']);
disp(['I3 = ',num2str(abs(I3)),' * exp(j* ', num2str(angle(I3)*180/pi), '°)']);

% komplexe Leistung der Quelle in VA
S = U0*conj(I1)
