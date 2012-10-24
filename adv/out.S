.data
mainhello: .long 0
maingoodbye: .asciz ""
.text
.globl main
main:
pushl (mainhello)
pushl $maingoodbye
.data
testrouthello: .long 0
testroutgoodbye: .asciz ""
.text
.globl testrout
testrout:
pushl (testrouthello)
pushl $testroutgoodbye
