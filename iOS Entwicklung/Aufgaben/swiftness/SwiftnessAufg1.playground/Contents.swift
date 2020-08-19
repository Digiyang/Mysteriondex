import Cocoa

var str = "Hello, playground"

enum CarType{
    case PKW, LKW
}

class Car  {
    var id = ""
    var typeOfCar = CarType.PKW
    var serialNumber = ""{

        didSet{
            if serialNumber.count > 12{
                serialNumber = String(serialNumber.dropLast(serialNumber.count - 12))
                Swift.print("Name too long. had to shorten it.")
            }

            if (self.typeOfCar == .PKW && serialNumber.contains("WBABA")){
                Swift.print("Sorry, WBABA cannot be there")
                self.serialNumber = oldValue
                }
        }
    }
    var numberOfAxis = 1
    var maxLoad = 0{
        willSet(newMaxLoad){
        }
        didSet{
            if (self.typeOfCar == .LKW && maxLoad/numberOfAxis > 2000){
                Swift.print("Sorry, too heavy")
                self.maxLoad = oldValue
            }
        }
    }
    
    init(){
    }

    func print(){
        Swift.print(" - ID of the car is: ", terminator : ""); Swift.print(self.id)
        Swift.print(" - type of the car is: ", terminator : ""); Swift.print(self.typeOfCar)
        Swift.print(" - serial number of this car is: ", terminator : ""); Swift.print(self.serialNumber)
        Swift.print(" - this car has so many axis:  ", terminator : ""); Swift.print(self.numberOfAxis)
        Swift.print(" - the maximum load of the car is: ", terminator : ""); Swift.print(self.maxLoad)
    }
}

//let mycar1 = Car(id: "mycar1", TypeOfCar : CarType.PKW, serialNumber : "powerWBABA", numberOfAxis : 1, maxLoad : 4500)

let mycar1 = Car()
let mycar2 = Car()
print("------------------------------------------------")
print("initalising a pkw with a SN that is too long....")
mycar1.id = "testPKW"
mycar1.serialNumber = "pfaodsaopdsaopdsAsdssd"
mycar1.maxLoad = 59
mycar1.print()


print("------------------------------------------------")
print("trying to put WBABA in PKWs name")
mycar1.serialNumber = "pWBABAfaodsaopdsaopdssdssd"
mycar1.print()


print("------------------------------------------------")
print("trying to make it very heavy")
mycar1.maxLoad = 594945594
mycar1.print()


print("------------------------------------------------")
print("initalising a lkw with a SN that is too long....")
mycar2.id = "test LKW"
mycar2.typeOfCar = .LKW
mycar2.serialNumber = "pfaodsaopdsaopWBABAdsAsdssd"
mycar2.print()

print("------------------------------------------------")
print("trying to make the LKW too heavy")
mycar2.maxLoad = 232323322434
mycar2.print()
