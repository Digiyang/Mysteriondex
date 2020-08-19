%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 8
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

U = 10;     % Spannung in V
I_R = 5;    % Strom durch Reihenschaltung in A
I_P = 20;   % Strom durch Parallelschaltung in A

R_P = U/I_P;
R_R = U/I_R;

R1 = R_R/2 + sqrt(R_R*(R_R/4-R_P))
R2 = R_R - R1