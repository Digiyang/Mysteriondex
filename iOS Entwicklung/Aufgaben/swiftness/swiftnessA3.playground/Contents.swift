import Cocoa

class Point  {
    var x , y : Double
    
    init(_ a: Double, _ b : Double){
        x = a
        y = b
    }
    
    init(){
        x = 0
        y = 0
    }
    
    func print(){
        Swift.print("Point => x: \(self.x), y: \(self.y) ");
    }
}

class Size {
    var width , height : Double
    
    init(_ a: Double, _ b : Double){
        width = a
        height = b
    }
    
    init(){
        width = 0
        height = 0
    }
    
    func print(){
        Swift.print("Size => width: \(self.width), height: \(self.height) ");
    }
}

class rE1 {
    var origin = Point()
    var size = Size()
   /* var rE2origin : Point {
        get {
        let rE2originx = self.origin.x + self.size.width
        let rE2originy = self.origin.y
        return Point( rE2originx,  rE2originy)
            }
        }
 */
    init(){
        
    }
    
    func print(){
        Swift.print("rE1 origin: x \(self.origin.x) , y \(self.origin.y)");
        Swift.print("rE1 size is: width \(self.size.width) , height \(self.size.height)");
        Swift.print("rE1 ends at: x \(self.origin.x+self.size.width)");
    }
}


class rE2 {
    var baseRect : rE1
    var size = Size()
    var origin : Point {
        get {
            let rE2originx = baseRect.origin.x + baseRect.size.width
            let rE2originy = baseRect.origin.y
            return Point(rE2originx, rE2originy)
        }
    }
    
    init(){
        size = Size()
        baseRect = rE1()
    }
    
    func print(){
        Swift.print("rE2 origin: x \(self.origin.x) , y \(self.origin.y)");
        Swift.print("rE2 size is: width \(self.size.width) , height \(self.size.height)");
        Swift.print("rE2 ends at: x \(self.origin.x+self.size.width)");
    }
}

print("========================")
print("Initialising a point")
let p1 = Point(34, 14)
//arbeiter1.print()
p1.print()

print("========================")
print("Initialising a size.")
let s1 = Size()
s1.print()


print("========================")
print("Initialising first rect")
let rect1 = rE1()
rect1.origin = Point(100, 100)
rect1.size.height = 50
rect1.size.width = 50
rect1.print()


print("========================")
print("Initialising a second rect")
let rect2 = rE2()
rect2.baseRect = rect1
rect2.size.height = 37
rect2.size.width = 100
rect2.print()

print("========================")
print("changing first rect")
rect1.origin = Point(250, 250)
rect1.size.height = 120
rect1.size.width = 120
rect1.print()

print("========================")
print("now the secon rect is")
rect2.print()

