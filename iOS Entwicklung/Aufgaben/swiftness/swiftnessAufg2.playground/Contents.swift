import Cocoa


class Mitarbeiter  {
    var Stundenzahl : Int
    var Name : String
    var Vorname: String
    var Mitarbeiternummer : Int
    var Anstellungsdatum = ""
    var Stundensatz : Float
    var JahreInDerFirma : Int
    lazy var Gehalt : Float = berechnetZeit * Float(Stundenzahl)
    
    var berechnetZeit :Float {
        return Float(self.Stundensatz) + (Float(self.JahreInDerFirma) * 0.75)
    }
    
    init(){
        Stundenzahl = 1
        Name = "a"
        Vorname = "b"
        Mitarbeiternummer = 1
        Anstellungsdatum = "01.01.01"
        Stundensatz = 1
        JahreInDerFirma = 1
    }
    
    func print(){
        Swift.print("Mitarbeiternr ", terminator : ""); Swift.print(self.Mitarbeiternummer)
        Swift.print(" - Name:  ", terminator : ""); Swift.print(self.Name)
        Swift.print(" - Vorname:  ", terminator : ""); Swift.print(self.Vorname)
        Swift.print(" - Anstellungsdatum:  ", terminator : ""); Swift.print(self.Anstellungsdatum)
        Swift.print(" - Stundenzahl: ", terminator : ""); Swift.print(self.Stundenzahl)
        Swift.print(" - Stundsatz: ", terminator : ""); Swift.print(self.Stundensatz)
        Swift.print(" - Gehalt: ", terminator : ""); Swift.print(self.Gehalt)
        
    }
}
print("========================")

print("Initialising a worker")
let arbeiter1 = Mitarbeiter()
//arbeiter1.print()

print("========================")
print("changing his/her salary")
arbeiter1.Stundenzahl = 240
arbeiter1.JahreInDerFirma = 15
arbeiter1.Stundensatz = 11.3
arbeiter1.print()
