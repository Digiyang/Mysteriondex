protocol Log{
    func logMe(somestring: String)
}

class loggerin  {
    var delegate : Log? = nil
    func loge(parameter: String){
        delegate!.logMe(somestring: parameter)
    }

}

struct Delegatin1 : Log{
    func logMe(somestring: String){
        if !somestring.contains("1"){
            Swift.print("--doesn't have the 1")
        }
    }
    
}

struct Delegatin2 : Log{
    func logMe(somestring: String){
        if !somestring.contains("2"){
            Swift.print("--doesn't have the 2")
        }
    }
    
}

struct Delegatin3 : Log{
    func logMe(somestring: String){
        if !somestring.contains("3"){
            Swift.print("--doesn't have the 3")
        }
    }
    
}
print("========================")
print("Initialising a loggerin1")
let loggerin1 = loggerin()

print("========================")
print("set Delegatin1 on the loggerin1. next -> send a string with 1 to loggerin1")
loggerin1.delegate = Delegatin1()
loggerin1.loge(parameter: "yikes! one one here: 1. 2 3 [you should not see this string!]")
print("send a string without 1 to loggerin1")
loggerin1.loge(parameter: "yuppi! number not here. [you should not see this string!]")


print("========================")
print("set Delegatin2 on the loggerin1. next -> send a string with 2 to loggerin1")
loggerin1.delegate = Delegatin2()
loggerin1.loge(parameter: "yikes! one two here: 2. 1 3[you should not see this string!]")
print("send a string without 2 to loggerin1")
loggerin1.loge(parameter: "yuppi! number not here. [you should not see this string!]")


print("========================")
print("set Delegatin3 on the loggerin1. next -> send a string with 3 to loggerin1")
loggerin1.delegate = Delegatin3()
loggerin1.loge(parameter: "yikes! one three here: 3. 1 2 [you should not see this string!]")
print("send a string without 2 to loggerin1")
loggerin1.loge(parameter: "yuppi! number not here. [you should not see this string!]")

