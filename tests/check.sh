
ERR_COUNTER=0


test_case1() {
    grep log1 test.log >/dev/null
    if [ $? -eq 0 ] ; then
        echo "log INFO level [passed]"
    else
        echo "log INFO level [failed]"
    fi
}


test_case2() {
    grep log2 test.log >/dev/null
    if [ $? -eq 1 ] ; then
        echo "change log INFO level [passed]"
    else
        echo "change log INFO level [failed]"
    fi
}

test_case3() {
    grep log3 test.log >/dev/null
    if [ $? -eq 0 ] ; then
        echo "log DEBUG level [passed]"
    else
        echo "log DEBUG level [failed]"
    fi
}

# main

for i in 1 2 3 ; do
eval test_case$i
done
