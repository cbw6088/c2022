fun main() {
    var input = readln().toInt()

    repeat(input){
        var value = readln().split(" ")
        var num = value[0].toInt()
        var str = value[1]
        var idx = 0
//        print(num)
//        print('\n')
//        print(str)
//        print('\n')
        repeat(str.length){
            repeat(num){
                print(str[idx])
            }
            idx++
        }
        print('\n')
    }
}