fun main(){
    var n = readln().toInt()
    var m = readln().split(" ")
    var list = ArrayList<Int>()
    for(i in m){
        list.add(i.toInt())
    }
    var flag:Int = 0
    var cnt:Int = 0
    for(i in 0..n-1){
        if(list[i] == 1) continue
        for(j in 2..list[i]-1){
            var test = list[i]
            if(test % j == 0) {
                flag = 1
                break
            }
        }
        if(flag == 1){
            flag = 0
        }
        else{
            cnt++
        }
    }
    print(cnt)
}