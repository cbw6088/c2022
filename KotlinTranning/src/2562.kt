fun main(){
    var num = Array<Int>(9,{0})
    for(i in 0..8){
        var N = readLine()
        num[i] = N!!.toInt()
    }
    var max = num.max()
    var idx = max.let{num.indexOf(it)} + 1
    print(max)
    print('\n')
    print(idx)
}