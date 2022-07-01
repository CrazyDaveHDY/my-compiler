lui $sp,0x1001
j main
main:
addi $s7 $zero 10
addi $s6 $zero 8
sw $s7 8($sp)
sw $s6 12($sp)
Label1:
lw $s7 8($sp)
addi $s6 $zero 0
blt $s7 $s6 Label4
Label2:
lw $s7 12($sp)
sw $s7 24($sp)
sw $s7 28($sp)
sw $sp 16($sp)
addi $sp $sp 16
jal mul
lw $sp 0($sp)
Label3:
lw $s7 8($sp)
addi $s6 $zero 1
sub $s7 $s7 $s6
sw $s7 8($sp)
sw $v0 12($sp)
j Label1
Label4:
j end
mul:
sw $ra 4($sp)
lw $s7 8($sp)
lw $s6 12($sp)
mul $s7 $s7 $s6
add $v0 $zero $s7
lw $ra 4($sp)
jr $ra
end:
