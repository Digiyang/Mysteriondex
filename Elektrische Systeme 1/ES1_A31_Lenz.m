%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterloesung - Aufgabe 31
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule fuer Technik Berlin
%--------------------------------------------------------------
%
% Das uebliche vorgehen
%
clear
close all
home
%
% Definition der in der Aufgabenstellung gegebenen Groessen
%
R = 1.4e3;   % in Ohm
L = 0.2e-3;   % in H
C = 100e-12;   % in F
%
% Festlegung der darzustellenden Frequenzen unter Beruecksichtigung der zu 
% waehlenden Darstellung 
% -> hier logarithmische aufteilung der Frequenzen, da der darzustellende 
%    Frequenzbereich von 1 Hz bis 100e6 Hz reicht !!
%
% logarithmisch geteilter Frequenzvektor von 1 Hz bis 0.1 GHz
f = logspace(0,8,1000); % Frequenz in Hz
                        % Die Darstellung erfolgt 1000 Punkten, die 
                        % logarithmischvon von 1e0==1 bis 1e8==100e6 verteilt
                        % sind
%
% Definition Hilfsgroessen
%
om = 2*pi*f;            % Kreisfrequenz in 1/s
%
% Definition des zu beruecksichtigen komplexen elektrischen Widerstandes 
% Aus U=R*I wird U=Z*I 
% Komplexen Widerstand als Vektor abhaengig von om berechnen
Z_RC = R + 1./(j*om*C);    % Reihenschaltung von R und C
Y = 1./Z_RC + 1./(j*om*L); % Parallelschaltung von L und RC
                           % hier Berechnug über die Addition der 
                           % komlexen elektrischen Leitwerte (Admittanzen)
Z = 1./Y;                  % Der Kehrwert des komplexen Leitwertes ist der 
                           % komplexe Widerstand
%
% Einfache grafische Darstellung
%
figure(1)
plot(Z,'r')     % Ortskurve (in rot) zeichnen
axis('equal')   % Beide Achsen gleich skalieren
grid
title('Ortskurve des komplexen Widerstandes')
xlabel('Realteil von Z')
ylabel('Imaginaerteil von Z')
%
% Fuer eine "schoenere" Grafik
%
figure(2)
set(plot(Z,'r'),"linewidth",2)
grid
axis('equal')
xlim ([-100,2000]);
ylim ([-100,1600]);
set(title('Ortskurve des komplexen Widerstandes'),"fontsize",18)
xlabel('Realteil von Z','FontSize',16,'FontWeight','bold')
ylabel('Imaginaerteil von Z','FontSize',16,'FontWeight','bold')