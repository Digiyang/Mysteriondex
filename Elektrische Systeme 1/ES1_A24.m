%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 24
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

f = 50;                    % Frequenz in H
om = 2*pi*f;               % Kreisfrequenz in 1/s
U = 220;                   % Spannung in V
P = 7000;				   % Wirkleistung in W
cosphi = 0.75;             % Leistungsfaktor

I_Betrag = P/(U*cosphi)   % Betrag von I
Q = U*I_Betrag*sqrt(1-cosphi^2) % Blindleistung mit: sin^2(phi)+cos^2(phi)=1
R = P/I_Betrag^2           % Widerstand
L = Q/(I_Betrag^2*om)      % Induktivität
S_Betrag = U*I_Betrag      % Betrag der Scheinleistung
S = P + j*Q				   % komplexe Scheinleistung
