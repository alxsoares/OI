asm(
"	.file	\"POSTAL.cpp\"\n"
"	.text\n"
"	.p2align 4,,15\n"
"	.type	_ZSt16__insertion_sortIP5QueryEvT_S2_.constprop.1, @function\n"
"_ZSt16__insertion_sortIP5QueryEvT_S2_.constprop.1:\n"
".LFB464:\n"
"	.cfi_startproc\n"
"	pushl	%ebp\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_offset 5, -8\n"
"	pushl	%edi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_offset 7, -12\n"
"	pushl	%esi\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_offset 6, -16\n"
"	pushl	%ebx\n"
"	.cfi_def_cfa_offset 20\n"
"	.cfi_offset 3, -20\n"
"	subl	$60, %esp\n"
"	.cfi_def_cfa_offset 80\n"
"	cmpl	$query, %eax\n"
"	movl	%eax, 40(%esp)\n"
"	je	.L1\n"
"	cmpl	$query+16, %eax\n"
"	je	.L1\n"
"	movl	$query+16, %ebx\n"
"	movl	$query+32, %edi\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L11:\n"
"	movl	4(%ebx), %esi\n"
"	movl	%ebx, %edx\n"
"	cmpl	query+4, %esi\n"
"	movl	(%ebx), %ebp\n"
"	jle	.L19\n"
".L3:\n"
"	movl	8(%ebx), %eax\n"
"	cmpl	-12(%ebx), %esi\n"
"	movl	%eax, 36(%esp)\n"
"	movl	12(%ebx), %eax\n"
"	movl	%eax, 44(%esp)\n"
"	jg	.L12\n"
"	jl	.L15\n"
"	cmpl	-16(%ebx), %ebp\n"
"	jae	.L12\n"
".L15:\n"
"	leal	-16(%ebx), %eax\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L9:\n"
"	movl	(%eax), %ecx\n"
"	movl	%ecx, (%edx)\n"
"	movl	4(%eax), %ecx\n"
"	movl	%ecx, 4(%edx)\n"
"	movl	8(%eax), %ecx\n"
"	movl	%ecx, 8(%edx)\n"
"	movl	12(%eax), %ecx\n"
"	movl	%ecx, 12(%edx)\n"
"	leal	-16(%eax), %ecx\n"
"	cmpl	4(%ecx), %esi\n"
"	jl	.L13\n"
"	jle	.L20\n"
".L7:\n"
"	movl	36(%esp), %edx\n"
"	movl	%ebp, (%eax)\n"
"	movl	%esi, 4(%eax)\n"
"	movl	%edx, 8(%eax)\n"
"	movl	44(%esp), %edx\n"
"	movl	%edx, 12(%eax)\n"
"	movl	%edi, %edx\n"
".L6:\n"
"	addl	$16, %ebx\n"
"	addl	$16, %edi\n"
"	cmpl	%edx, 40(%esp)\n"
"	jne	.L11\n"
".L1:\n"
"	addl	$60, %esp\n"
"	.cfi_remember_state\n"
"	.cfi_def_cfa_offset 20\n"
"	popl	%ebx\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_restore 3\n"
"	popl	%esi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_restore 6\n"
"	popl	%edi\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_restore 7\n"
"	popl	%ebp\n"
"	.cfi_def_cfa_offset 4\n"
"	.cfi_restore 5\n"
"	ret\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L20:\n"
"	.cfi_restore_state\n"
"	cmpl	(%ecx), %ebp\n"
"	jae	.L7\n"
".L13:\n"
"	movl	%eax, %edx\n"
"	movl	%ecx, %eax\n"
"	jmp	.L9\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L19:\n"
"	jl	.L14\n"
"	cmpl	query, %ebp\n"
"	jae	.L3\n"
".L14:\n"
"	movl	12(%ebx), %edx\n"
"	movl	%ebx, %eax\n"
"	subl	$query, %eax\n"
"	movl	8(%ebx), %ecx\n"
"	sarl	$4, %eax\n"
"	testl	%eax, %eax\n"
"	movl	%edx, 36(%esp)\n"
"	movl	%edi, %edx\n"
"	jne	.L21\n"
".L5:\n"
"	movl	36(%esp), %eax\n"
"	movl	%ebp, query\n"
"	movl	%esi, query+4\n"
"	movl	%ecx, query+8\n"
"	movl	%eax, query+12\n"
"	jmp	.L6\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L21:\n"
"	sall	$4, %eax\n"
"	movl	%eax, 44(%esp)\n"
"	movl	%eax, 8(%esp)\n"
"	movl	%edi, %eax\n"
"	subl	44(%esp), %eax\n"
"	movl	%ecx, 32(%esp)\n"
"	movl	$query, 4(%esp)\n"
"	movl	%eax, (%esp)\n"
"	movl	%edi, 28(%esp)\n"
"	call	memmove\n"
"	movl	32(%esp), %ecx\n"
"	movl	28(%esp), %edx\n"
"	jmp	.L5\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L12:\n"
"	movl	%ebx, %eax\n"
"	jmp	.L7\n"
"	.cfi_endproc\n"
".LFE464:\n"
"	.size	_ZSt16__insertion_sortIP5QueryEvT_S2_.constprop.1, .-_ZSt16__insertion_sortIP5QueryEvT_S2_.constprop.1\n"
"	.section	.text._ZSt19__move_median_firstIP5QueryEvT_S2_S2_,\"axG\",@progbits,_ZSt19__move_median_firstIP5QueryEvT_S2_S2_,comdat\n"
"	.p2align 4,,15\n"
"	.weak	_ZSt19__move_median_firstIP5QueryEvT_S2_S2_\n"
"	.type	_ZSt19__move_median_firstIP5QueryEvT_S2_S2_, @function\n"
"_ZSt19__move_median_firstIP5QueryEvT_S2_S2_:\n"
".LFB444:\n"
"	.cfi_startproc\n"
"	subl	$36, %esp\n"
"	.cfi_def_cfa_offset 40\n"
"	movl	44(%esp), %edx\n"
"	movl	40(%esp), %eax\n"
"	movl	%esi, 24(%esp)\n"
"	movl	48(%esp), %ecx\n"
"	movl	%ebx, 20(%esp)\n"
"	movl	(%edx), %esi\n"
"	.cfi_offset 3, -20\n"
"	.cfi_offset 6, -16\n"
"	movl	4(%eax), %ebx\n"
"	movl	%edi, 28(%esp)\n"
"	movl	(%eax), %edi\n"
"	.cfi_offset 7, -12\n"
"	movl	%ebp, 32(%esp)\n"
"	movl	%esi, 4(%esp)\n"
"	movl	4(%edx), %esi\n"
"	cmpl	%esi, %ebx\n"
"	jg	.L23\n"
"	.cfi_offset 5, -8\n"
"	jge	.L37\n"
".L32:\n"
"	movl	(%ecx), %ebp\n"
"	movl	%ebp, 12(%esp)\n"
"	movl	4(%ecx), %ebp\n"
"	cmpl	%ebp, %esi\n"
"	movl	%ebp, 8(%esp)\n"
"	jle	.L38\n"
".L25:\n"
"	cmpl	8(%esp), %ebx\n"
"	jg	.L22\n"
"	jl	.L36\n"
"	cmpl	12(%esp), %edi\n"
"	.p2align 4,,3\n"
"	jb	.L36\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L22:\n"
"	movl	20(%esp), %ebx\n"
"	movl	24(%esp), %esi\n"
"	movl	28(%esp), %edi\n"
"	movl	32(%esp), %ebp\n"
"	addl	$36, %esp\n"
"	.cfi_remember_state\n"
"	.cfi_def_cfa_offset 4\n"
"	.cfi_restore 5\n"
"	.cfi_restore 7\n"
"	.cfi_restore 6\n"
"	.cfi_restore 3\n"
"	ret\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L37:\n"
"	.cfi_restore_state\n"
"	cmpl	4(%esp), %edi\n"
"	jb	.L32\n"
".L23:\n"
"	movl	(%ecx), %ebp\n"
"	movl	%ebp, 12(%esp)\n"
"	movl	4(%ecx), %ebp\n"
"	cmpl	%ebp, %ebx\n"
"	movl	%ebp, 8(%esp)\n"
"	jl	.L22\n"
"	jle	.L39\n"
".L35:\n"
"	cmpl	8(%esp), %esi\n"
"	jg	.L30\n"
"	.p2align 4,,7\n"
"	jl	.L36\n"
"	movl	12(%esp), %esi\n"
"	cmpl	%esi, 4(%esp)\n"
"	jb	.L36\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L30:\n"
"	movl	(%edx), %ebp\n"
"	movl	8(%eax), %esi\n"
"	movl	12(%eax), %ecx\n"
"	movl	%ebp, (%eax)\n"
"	movl	4(%edx), %ebp\n"
"	movl	%ebp, 4(%eax)\n"
"	movl	8(%edx), %ebp\n"
"	movl	%ebp, 8(%eax)\n"
"	movl	12(%edx), %ebp\n"
"	movl	%ebp, 12(%eax)\n"
"	movl	%edi, (%edx)\n"
"	movl	%ebx, 4(%edx)\n"
"	movl	%esi, 8(%edx)\n"
"	movl	%ecx, 12(%edx)\n"
"	jmp	.L22\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L38:\n"
"	jl	.L30\n"
"	movl	12(%esp), %esi\n"
"	cmpl	%esi, 4(%esp)\n"
"	jae	.L25\n"
"	.p2align 4,,3\n"
"	jmp	.L30\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L39:\n"
"	cmpl	12(%esp), %edi\n"
"	jb	.L22\n"
"	.p2align 4,,7\n"
"	jmp	.L35\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L36:\n"
"	movl	(%ecx), %ebp\n"
"	movl	8(%eax), %esi\n"
"	movl	12(%eax), %edx\n"
"	movl	%ebp, (%eax)\n"
"	movl	4(%ecx), %ebp\n"
"	movl	%ebp, 4(%eax)\n"
"	movl	8(%ecx), %ebp\n"
"	movl	%ebp, 8(%eax)\n"
"	movl	12(%ecx), %ebp\n"
"	movl	%ebp, 12(%eax)\n"
"	movl	%edi, (%ecx)\n"
"	movl	%ebx, 4(%ecx)\n"
"	movl	%esi, 8(%ecx)\n"
"	movl	%edx, 12(%ecx)\n"
"	jmp	.L22\n"
"	.cfi_endproc\n"
".LFE444:\n"
"	.size	_ZSt19__move_median_firstIP5QueryEvT_S2_S2_, .-_ZSt19__move_median_firstIP5QueryEvT_S2_S2_\n"
"	.section	.text._ZSt11__push_heapIP5QueryiS0_EvT_T0_S3_T1_,\"axG\",@progbits,_ZSt11__push_heapIP5QueryiS0_EvT_T0_S3_T1_,comdat\n"
"	.p2align 4,,15\n"
"	.weak	_ZSt11__push_heapIP5QueryiS0_EvT_T0_S3_T1_\n"
"	.type	_ZSt11__push_heapIP5QueryiS0_EvT_T0_S3_T1_, @function\n"
"_ZSt11__push_heapIP5QueryiS0_EvT_T0_S3_T1_:\n"
".LFB458:\n"
"	.cfi_startproc\n"
"	pushl	%ebp\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_offset 5, -8\n"
"	pushl	%edi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_offset 7, -12\n"
"	pushl	%esi\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_offset 6, -16\n"
"	pushl	%ebx\n"
"	.cfi_def_cfa_offset 20\n"
"	.cfi_offset 3, -20\n"
"	movl	24(%esp), %ebp\n"
"	cmpl	28(%esp), %ebp\n"
"	movl	20(%esp), %ebx\n"
"	movl	32(%esp), %edi\n"
"	movl	36(%esp), %esi\n"
"	jle	.L49\n"
"	leal	-1(%ebp), %eax\n"
"	movl	%eax, %ecx\n"
"	shrl	$31, %ecx\n"
"	addl	%eax, %ecx\n"
"	sarl	%ecx\n"
"	movl	%ecx, %eax\n"
"	sall	$4, %eax\n"
"	addl	%ebx, %eax\n"
"	cmpl	4(%eax), %esi\n"
"	jle	.L55\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L50:\n"
"	movl	%ecx, %edx\n"
"	movl	%ebp, %eax\n"
"	sall	$4, %edx\n"
"	addl	%ebx, %edx\n"
"	movl	(%edx), %ebp\n"
"	sall	$4, %eax\n"
"	addl	%ebx, %eax\n"
"	cmpl	%ecx, 28(%esp)\n"
"	movl	%ebp, (%eax)\n"
"	movl	4(%edx), %ebp\n"
"	movl	%ebp, 4(%eax)\n"
"	movl	8(%edx), %ebp\n"
"	movl	%ebp, 8(%eax)\n"
"	movl	12(%edx), %ebp\n"
"	movl	%ebp, 12(%eax)\n"
"	jl	.L47\n"
".L42:\n"
"	movl	40(%esp), %eax\n"
"	movl	%edi, (%edx)\n"
"	movl	%esi, 4(%edx)\n"
"	movl	%eax, 8(%edx)\n"
"	movl	44(%esp), %eax\n"
"	movl	%eax, 12(%edx)\n"
"	popl	%ebx\n"
"	.cfi_remember_state\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_restore 3\n"
"	popl	%esi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_restore 6\n"
"	popl	%edi\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_restore 7\n"
"	popl	%ebp\n"
"	.cfi_def_cfa_offset 4\n"
"	.cfi_restore 5\n"
"	ret\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L47:\n"
"	.cfi_restore_state\n"
"	leal	-1(%ecx), %eax\n"
"	movl	%eax, %ebp\n"
"	shrl	$31, %ebp\n"
"	addl	%ebp, %eax\n"
"	sarl	%eax\n"
"	movl	%eax, %ebp\n"
"	sall	$4, %ebp\n"
"	addl	%ebx, %ebp\n"
"	cmpl	%esi, 4(%ebp)\n"
"	jl	.L48\n"
"	jg	.L42\n"
"	cmpl	%edi, 0(%ebp)\n"
"	jae	.L42\n"
".L48:\n"
"	movl	%ecx, %ebp\n"
"	movl	%eax, %ecx\n"
"	.p2align 4,,4\n"
"	jmp	.L50\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L55:\n"
"	jl	.L49\n"
"	cmpl	(%eax), %edi\n"
"	.p2align 4,,5\n"
"	ja	.L50\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L49:\n"
"	movl	%ebp, %edx\n"
"	sall	$4, %edx\n"
"	addl	%ebx, %edx\n"
"	.p2align 4,,2\n"
"	jmp	.L42\n"
"	.cfi_endproc\n"
".LFE458:\n"
"	.size	_ZSt11__push_heapIP5QueryiS0_EvT_T0_S3_T1_, .-_ZSt11__push_heapIP5QueryiS0_EvT_T0_S3_T1_\n"
"	.section	.text._ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_,\"axG\",@progbits,_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_,comdat\n"
"	.p2align 4,,15\n"
"	.weak	_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_\n"
"	.type	_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_, @function\n"
"_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_:\n"
".LFB453:\n"
"	.cfi_startproc\n"
"	pushl	%ebp\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_offset 5, -8\n"
"	pushl	%edi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_offset 7, -12\n"
"	pushl	%esi\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_offset 6, -16\n"
"	pushl	%ebx\n"
"	.cfi_def_cfa_offset 20\n"
"	.cfi_offset 3, -20\n"
"	subl	$44, %esp\n"
"	.cfi_def_cfa_offset 64\n"
"	movl	68(%esp), %eax\n"
"	movl	72(%esp), %ebx\n"
"	movl	64(%esp), %ecx\n"
"	movl	%eax, 24(%esp)\n"
"	movl	24(%esp), %edi\n"
"	movl	%ebx, %eax\n"
"	subl	$1, %eax\n"
"	movl	%eax, %edx\n"
"	shrl	$31, %edx\n"
"	addl	%eax, %edx\n"
"	movl	%edx, 20(%esp)\n"
"	sarl	20(%esp)\n"
"	movl	20(%esp), %ebp\n"
"	movl	%ebx, 28(%esp)\n"
"	cmpl	%ebp, %edi\n"
"	jge	.L57\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L67:\n"
"	leal	1(%edi), %edx\n"
"	movl	%edi, %eax\n"
"	leal	(%edx,%edx), %edi\n"
"	sall	$5, %edx\n"
"	addl	%ecx, %edx\n"
"	movl	(%edx), %ebx\n"
"	leal	-1(%edi), %ebp\n"
"	movl	4(%edx), %esi\n"
"	movl	%ebp, 8(%esp)\n"
"	movl	%ebx, 12(%esp)\n"
"	movl	%ebp, %ebx\n"
"	sall	$4, %ebx\n"
"	addl	%ecx, %ebx\n"
"	movl	(%ebx), %ebp\n"
"	movl	4(%ebx), %ebx\n"
"	movl	%ebp, 16(%esp)\n"
"	cmpl	%ebx, %esi\n"
"	jg	.L59\n"
"	jl	.L60\n"
"	cmpl	%ebp, 12(%esp)\n"
"	jae	.L59\n"
".L60:\n"
"	movl	8(%esp), %edi\n"
".L59:\n"
"	sall	$4, %eax\n"
"	addl	%ecx, %eax\n"
"	cmpl	%ebx, %esi\n"
"	jg	.L62\n"
"	jl	.L63\n"
"	movl	16(%esp), %ebx\n"
"	cmpl	%ebx, 12(%esp)\n"
"	jae	.L62\n"
".L63:\n"
"	movl	8(%esp), %edx\n"
"	sall	$4, %edx\n"
"	addl	%ecx, %edx\n"
".L62:\n"
"	movl	(%edx), %ebx\n"
"	cmpl	20(%esp), %edi\n"
"	movl	%ebx, (%eax)\n"
"	movl	4(%edx), %ebx\n"
"	movl	%ebx, 4(%eax)\n"
"	movl	8(%edx), %ebx\n"
"	movl	%ebx, 8(%eax)\n"
"	movl	12(%edx), %edx\n"
"	movl	%edx, 12(%eax)\n"
"	jl	.L67\n"
".L57:\n"
"	testb	$1, 28(%esp)\n"
"	jne	.L65\n"
"	movl	28(%esp), %eax\n"
"	subl	$2, %eax\n"
"	movl	%eax, %edx\n"
"	shrl	$31, %edx\n"
"	addl	%edx, %eax\n"
"	sarl	%eax\n"
"	cmpl	%eax, %edi\n"
"	je	.L68\n"
".L65:\n"
"	movl	24(%esp), %ebp\n"
"	movl	%edi, 68(%esp)\n"
"	movl	%ecx, 64(%esp)\n"
"	movl	%ebp, 72(%esp)\n"
"	addl	$44, %esp\n"
"	.cfi_remember_state\n"
"	.cfi_def_cfa_offset 20\n"
"	popl	%ebx\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_restore 3\n"
"	popl	%esi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_restore 6\n"
"	popl	%edi\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_restore 7\n"
"	popl	%ebp\n"
"	.cfi_def_cfa_offset 4\n"
"	.cfi_restore 5\n"
"	jmp	_ZSt11__push_heapIP5QueryiS0_EvT_T0_S3_T1_\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L68:\n"
"	.cfi_restore_state\n"
"	movl	%edi, %eax\n"
"	leal	1(%edi,%edi), %edi\n"
"	movl	%edi, %edx\n"
"	sall	$4, %edx\n"
"	addl	%ecx, %edx\n"
"	movl	(%edx), %ebx\n"
"	sall	$4, %eax\n"
"	addl	%ecx, %eax\n"
"	movl	%ebx, (%eax)\n"
"	movl	4(%edx), %ebx\n"
"	movl	%ebx, 4(%eax)\n"
"	movl	8(%edx), %ebx\n"
"	movl	%ebx, 8(%eax)\n"
"	movl	12(%edx), %edx\n"
"	movl	%edx, 12(%eax)\n"
"	jmp	.L65\n"
"	.cfi_endproc\n"
".LFE453:\n"
"	.size	_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_, .-_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_\n"
"	.section	.text._ZSt13__heap_selectIP5QueryEvT_S2_S2_,\"axG\",@progbits,_ZSt13__heap_selectIP5QueryEvT_S2_S2_,comdat\n"
"	.p2align 4,,15\n"
"	.weak	_ZSt13__heap_selectIP5QueryEvT_S2_S2_\n"
"	.type	_ZSt13__heap_selectIP5QueryEvT_S2_S2_, @function\n"
"_ZSt13__heap_selectIP5QueryEvT_S2_S2_:\n"
".LFB442:\n"
"	.cfi_startproc\n"
"	pushl	%ebp\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_offset 5, -8\n"
"	pushl	%edi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_offset 7, -12\n"
"	pushl	%esi\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_offset 6, -16\n"
"	pushl	%ebx\n"
"	.cfi_def_cfa_offset 20\n"
"	.cfi_offset 3, -20\n"
"	subl	$76, %esp\n"
"	.cfi_def_cfa_offset 96\n"
"	movl	96(%esp), %ebx\n"
"	movl	100(%esp), %eax\n"
"	subl	%ebx, %eax\n"
"	cmpl	$31, %eax\n"
"	movl	%eax, 44(%esp)\n"
"	jle	.L73\n"
"	sarl	$4, %eax\n"
"	movl	%eax, %edi\n"
"	subl	$2, %edi\n"
"	sarl	%edi\n"
"	movl	%edi, %esi\n"
"	sall	$4, %esi\n"
"	movl	%eax, 40(%esp)\n"
"	addl	%ebx, %esi\n"
"	jmp	.L74\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L83:\n"
"	subl	$1, %edi\n"
".L74:\n"
"	movl	8(%esi), %edx\n"
"	movl	(%esi), %ebp\n"
"	movl	4(%esi), %ecx\n"
"	movl	12(%esi), %eax\n"
"	subl	$16, %esi\n"
"	movl	%edx, 56(%esp)\n"
"	movl	%edx, 20(%esp)\n"
"	movl	40(%esp), %edx\n"
"	movl	%ebp, 48(%esp)\n"
"	movl	%ecx, 52(%esp)\n"
"	movl	%eax, 60(%esp)\n"
"	movl	%ebp, 12(%esp)\n"
"	movl	%ecx, 16(%esp)\n"
"	movl	%eax, 24(%esp)\n"
"	movl	%edx, 8(%esp)\n"
"	movl	%edi, 4(%esp)\n"
"	movl	%ebx, (%esp)\n"
"	call	_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_\n"
"	testl	%edi, %edi\n"
"	jne	.L83\n"
".L73:\n"
"	movl	44(%esp), %edx\n"
"	movl	100(%esp), %esi\n"
"	movl	104(%esp), %edi\n"
"	sarl	$4, %edx\n"
"	cmpl	104(%esp), %esi\n"
"	movl	%edx, 44(%esp)\n"
"	jae	.L69\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L79:\n"
"	movl	4(%ebx), %edx\n"
"	cmpl	%edx, 4(%esi)\n"
"	movl	(%esi), %eax\n"
"	jg	.L75\n"
"	jl	.L78\n"
"	cmpl	(%ebx), %eax\n"
"	jae	.L75\n"
".L78:\n"
"	movl	12(%esi), %eax\n"
"	movl	8(%esi), %edx\n"
"	movl	(%esi), %ebp\n"
"	movl	4(%esi), %ecx\n"
"	movl	%eax, 60(%esp)\n"
"	movl	%eax, 24(%esp)\n"
"	movl	(%ebx), %eax\n"
"	movl	%edx, 56(%esp)\n"
"	movl	%ebp, 48(%esp)\n"
"	movl	%ecx, 52(%esp)\n"
"	movl	%eax, (%esi)\n"
"	movl	4(%ebx), %eax\n"
"	movl	%eax, 4(%esi)\n"
"	movl	8(%ebx), %eax\n"
"	movl	%eax, 8(%esi)\n"
"	movl	12(%ebx), %eax\n"
"	movl	%eax, 12(%esi)\n"
"	movl	%edx, 20(%esp)\n"
"	movl	44(%esp), %edx\n"
"	movl	%ebp, 12(%esp)\n"
"	movl	%ecx, 16(%esp)\n"
"	movl	$0, 4(%esp)\n"
"	movl	%edx, 8(%esp)\n"
"	movl	%ebx, (%esp)\n"
"	call	_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_\n"
".L75:\n"
"	addl	$16, %esi\n"
"	cmpl	%esi, %edi\n"
"	ja	.L79\n"
".L69:\n"
"	addl	$76, %esp\n"
"	.cfi_def_cfa_offset 20\n"
"	popl	%ebx\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_restore 3\n"
"	popl	%esi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_restore 6\n"
"	popl	%edi\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_restore 7\n"
"	popl	%ebp\n"
"	.cfi_def_cfa_offset 4\n"
"	.cfi_restore 5\n"
"	ret\n"
"	.cfi_endproc\n"
".LFE442:\n"
"	.size	_ZSt13__heap_selectIP5QueryEvT_S2_S2_, .-_ZSt13__heap_selectIP5QueryEvT_S2_S2_\n"
"	.section	.text._ZSt16__introsort_loopIP5QueryiEvT_S2_T0_,\"axG\",@progbits,_ZSt16__introsort_loopIP5QueryiEvT_S2_T0_,comdat\n"
"	.p2align 4,,15\n"
"	.weak	_ZSt16__introsort_loopIP5QueryiEvT_S2_T0_\n"
"	.type	_ZSt16__introsort_loopIP5QueryiEvT_S2_T0_, @function\n"
"_ZSt16__introsort_loopIP5QueryiEvT_S2_T0_:\n"
".LFB436:\n"
"	.cfi_startproc\n"
"	pushl	%ebp\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_offset 5, -8\n"
"	pushl	%edi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_offset 7, -12\n"
"	pushl	%esi\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_offset 6, -16\n"
"	pushl	%ebx\n"
"	.cfi_def_cfa_offset 20\n"
"	.cfi_offset 3, -20\n"
"	subl	$76, %esp\n"
"	.cfi_def_cfa_offset 96\n"
"	movl	96(%esp), %ebp\n"
"	movl	100(%esp), %eax\n"
"	subl	%ebp, %eax\n"
"	cmpl	$271, %eax\n"
"	jle	.L84\n"
"	movl	104(%esp), %edx\n"
"	testl	%edx, %edx\n"
"	je	.L100\n"
"	movl	100(%esp), %edx\n"
"	leal	16(%ebp), %edi\n"
"	movl	%edi, 44(%esp)\n"
".L87:\n"
"	sarl	$5, %eax\n"
"	subl	$16, %edx\n"
"	sall	$4, %eax\n"
"	addl	%ebp, %eax\n"
"	movl	%eax, 4(%esp)\n"
"	subl	$1, 104(%esp)\n"
"	movl	%edx, 8(%esp)\n"
"	movl	%ebp, (%esp)\n"
"	call	_ZSt19__move_median_firstIP5QueryEvT_S2_S2_\n"
"	movl	100(%esp), %eax\n"
"	movl	44(%esp), %ebx\n"
"	jmp	.L99\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L102:\n"
"	movl	40(%esp), %eax\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L93:\n"
"	cmpl	%eax, %ebx\n"
"	jae	.L115\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L97:\n"
"	movl	8(%ebx), %edi\n"
"	movl	12(%ebx), %edx\n"
"	movl	%edi, 40(%esp)\n"
"	movl	(%eax), %edi\n"
"	movl	%edi, (%ebx)\n"
"	movl	4(%eax), %edi\n"
"	movl	%edi, 4(%ebx)\n"
"	movl	8(%eax), %edi\n"
"	movl	%edi, 8(%ebx)\n"
"	movl	12(%eax), %edi\n"
"	movl	%edi, 12(%ebx)\n"
"	addl	$16, %ebx\n"
"	movl	%ecx, 4(%eax)\n"
"	movl	40(%esp), %ecx\n"
"	movl	%esi, (%eax)\n"
"	movl	%edx, 12(%eax)\n"
"	movl	%ecx, 8(%eax)\n"
".L99:\n"
"	movl	0(%ebp), %edx\n"
"	movl	4(%ebx), %ecx\n"
"	movl	(%ebx), %esi\n"
"	movl	%edx, 36(%esp)\n"
"	movl	4(%ebp), %edx\n"
"	cmpl	%edx, %ecx\n"
"	jg	.L89\n"
"	jl	.L112\n"
"	cmpl	36(%esp), %esi\n"
"	jae	.L89\n"
".L112:\n"
"	movl	36(%esp), %edi\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L110:\n"
"	addl	$16, %ebx\n"
"	movl	4(%ebx), %ecx\n"
"	movl	(%ebx), %esi\n"
"	cmpl	%edx, %ecx\n"
"	jl	.L110\n"
"	jg	.L113\n"
"	cmpl	%edi, %esi\n"
"	jb	.L110\n"
".L113:\n"
"	movl	%edi, 36(%esp)\n"
".L89:\n"
"	cmpl	%edx, -12(%eax)\n"
"	leal	-16(%eax), %edi\n"
"	movl	%edi, 40(%esp)\n"
"	jl	.L102\n"
"	jg	.L103\n"
"	movl	36(%esp), %edi\n"
"	cmpl	%edi, -16(%eax)\n"
"	jbe	.L102\n"
".L103:\n"
"	movl	40(%esp), %eax\n"
"	movl	36(%esp), %edi\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L111:\n"
"	subl	$16, %eax\n"
"	cmpl	%edx, 4(%eax)\n"
"	jg	.L111\n"
"	jl	.L93\n"
"	cmpl	%edi, (%eax)\n"
"	ja	.L111\n"
"	cmpl	%eax, %ebx\n"
"	.p2align 4,,7\n"
"	jb	.L97\n"
".L115:\n"
"	movl	104(%esp), %eax\n"
"	movl	100(%esp), %edx\n"
"	movl	%ebx, (%esp)\n"
"	movl	%eax, 8(%esp)\n"
"	movl	%edx, 4(%esp)\n"
"	call	_ZSt16__introsort_loopIP5QueryiEvT_S2_T0_\n"
"	movl	%ebx, %eax\n"
"	subl	%ebp, %eax\n"
"	cmpl	$271, %eax\n"
"	jle	.L84\n"
"	movl	104(%esp), %ecx\n"
"	movl	%ebx, 100(%esp)\n"
"	testl	%ecx, %ecx\n"
"	je	.L100\n"
"	movl	%ebx, %edx\n"
"	jmp	.L87\n"
".L100:\n"
"	movl	100(%esp), %eax\n"
"	movl	%ebp, (%esp)\n"
"	movl	%eax, 8(%esp)\n"
"	movl	%eax, 4(%esp)\n"
"	call	_ZSt13__heap_selectIP5QueryEvT_S2_S2_\n"
"	movl	100(%esp), %ebx\n"
".L88:\n"
"	movl	0(%ebp), %esi\n"
"	subl	$16, %ebx\n"
"	movl	(%ebx), %edi\n"
"	movl	4(%ebx), %ecx\n"
"	movl	8(%ebx), %edx\n"
"	movl	%esi, (%ebx)\n"
"	movl	4(%ebp), %esi\n"
"	movl	12(%ebx), %eax\n"
"	movl	%edi, 48(%esp)\n"
"	movl	%ecx, 52(%esp)\n"
"	movl	%esi, 4(%ebx)\n"
"	movl	8(%ebp), %esi\n"
"	movl	%eax, 60(%esp)\n"
"	movl	%edx, 56(%esp)\n"
"	movl	%esi, 8(%ebx)\n"
"	movl	12(%ebp), %esi\n"
"	movl	%esi, 12(%ebx)\n"
"	movl	%ebx, %esi\n"
"	subl	%ebp, %esi\n"
"	movl	%eax, 24(%esp)\n"
"	movl	%esi, %eax\n"
"	sarl	$4, %eax\n"
"	movl	%edi, 12(%esp)\n"
"	movl	%ecx, 16(%esp)\n"
"	movl	%edx, 20(%esp)\n"
"	movl	%eax, 8(%esp)\n"
"	movl	$0, 4(%esp)\n"
"	movl	%ebp, (%esp)\n"
"	call	_ZSt13__adjust_heapIP5QueryiS0_EvT_T0_S3_T1_\n"
"	cmpl	$31, %esi\n"
"	jg	.L88\n"
".L84:\n"
"	addl	$76, %esp\n"
"	.cfi_def_cfa_offset 20\n"
"	popl	%ebx\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_restore 3\n"
"	popl	%esi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_restore 6\n"
"	popl	%edi\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_restore 7\n"
"	popl	%ebp\n"
"	.cfi_def_cfa_offset 4\n"
"	.cfi_restore 5\n"
"	ret\n"
"	.cfi_endproc\n"
".LFE436:\n"
"	.size	_ZSt16__introsort_loopIP5QueryiEvT_S2_T0_, .-_ZSt16__introsort_loopIP5QueryiEvT_S2_T0_\n"
"	.section	.rodata.str1.1,\"aMS\",@progbits,1\n"
".LC0:\n"
"	.string	\"%d\"\n"
".LC1:\n"
"	.string	\"%lld\"\n"
".LC2:\n"
"	.string	\"%d%lld\"\n"
".LC3:\n"
"	.string	\"%lld %d\n\"\n"
"	.text\n"
"	.p2align 4,,15\n"
"	.globl	_Z5solvev\n"
"	.type	_Z5solvev, @function\n"
"_Z5solvev:\n"
".LFB429:\n"
"	.cfi_startproc\n"
"	pushl	%ebp\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_offset 5, -8\n"
"	pushl	%edi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_offset 7, -12\n"
"	pushl	%esi\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_offset 6, -16\n"
"	pushl	%ebx\n"
"	.cfi_def_cfa_offset 20\n"
"	.cfi_offset 3, -20\n"
"	subl	$92, %esp\n"
"	.cfi_def_cfa_offset 112\n"
"	movl	$nbee, 4(%esp)\n"
"	movl	$.LC0, (%esp)\n"
"	call	scanf\n"
"	movl	nbee, %edi\n"
"	testl	%edi, %edi\n"
"	jle	.L117\n"
"	xorl	%ebx, %ebx\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L118:\n"
"	leal	pos(,%ebx,8), %eax\n"
"	movl	%eax, 4(%esp)\n"
"	movl	$.LC1, (%esp)\n"
"	call	scanf\n"
"	movl	pos(,%ebx,8), %eax\n"
"	movl	pos+4(,%ebx,8), %edx\n"
"	shldl	$1, %eax, %edx\n"
"	addl	%eax, %eax\n"
"	movl	%eax, pos(,%ebx,8)\n"
"	movl	nbee, %eax\n"
"	movl	%edx, pos+4(,%ebx,8)\n"
"	addl	$1, %ebx\n"
"	cmpl	%ebx, %eax\n"
"	jg	.L118\n"
"	testl	%eax, %eax\n"
"	jle	.L117\n"
"	xorl	%ebx, %ebx\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L120:\n"
"	leal	dir(,%ebx,8), %eax\n"
"	movl	%eax, 4(%esp)\n"
"	movl	$.LC1, (%esp)\n"
"	call	scanf\n"
"	movl	dir+4(,%ebx,8), %eax\n"
"	orl	dir(,%ebx,8), %eax\n"
"	jne	.L119\n"
"	movl	$-1, dir(,%ebx,8)\n"
"	movl	$-1, dir+4(,%ebx,8)\n"
".L119:\n"
"	addl	$1, %ebx\n"
"	cmpl	%ebx, nbee\n"
"	jg	.L120\n"
".L117:\n"
"	movl	$nquery, 4(%esp)\n"
"	movl	$.LC0, (%esp)\n"
"	call	scanf\n"
"	movl	nquery, %ebx\n"
"	testl	%ebx, %ebx\n"
"	movl	%ebx, 72(%esp)\n"
"	jle	.L121\n"
"	movl	$query, %esi\n"
"	xorl	%ebx, %ebx\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L122:\n"
"	movl	%ebx, %eax\n"
"	sall	$4, %eax\n"
"	addl	$query, %eax\n"
"	movl	%eax, 8(%esp)\n"
"	addl	$8, %eax\n"
"	movl	%eax, 4(%esp)\n"
"	movl	$.LC2, (%esp)\n"
"	call	scanf\n"
"	movl	(%esi), %eax\n"
"	movl	4(%esi), %edx\n"
"	movl	%ebx, 12(%esi)\n"
"	addl	$1, %ebx\n"
"	shldl	$1, %eax, %edx\n"
"	addl	%eax, %eax\n"
"	movl	%eax, (%esi)\n"
"	movl	nquery, %eax\n"
"	movl	%edx, 4(%esi)\n"
"	addl	$16, %esi\n"
"	cmpl	%ebx, %eax\n"
"	jg	.L122\n"
"	movl	%eax, 72(%esp)\n"
"	movl	%eax, %ebx\n"
".L121:\n"
"	sall	$4, %ebx\n"
"	addl	$query, %ebx\n"
"	cmpl	$query, %ebx\n"
"	je	.L123\n"
"	movl	%ebx, %esi\n"
"	movl	$31, %eax\n"
"	subl	$query, %esi\n"
"	movl	%esi, %edx\n"
"	sarl	$4, %edx\n"
"	bsrl	%edx, %edx\n"
"	xorl	$31, %edx\n"
"	subl	%edx, %eax\n"
"	addl	%eax, %eax\n"
"	movl	%eax, 8(%esp)\n"
"	movl	%ebx, 4(%esp)\n"
"	movl	$query, (%esp)\n"
"	call	_ZSt16__introsort_loopIP5QueryiEvT_S2_T0_\n"
"	cmpl	$271, %esi\n"
"	jle	.L124\n"
"	movl	$query+256, %eax\n"
"	movl	$query+256, %edi\n"
"	call	_ZSt16__insertion_sortIP5QueryEvT_S2_.constprop.1\n"
"	cmpl	%edi, %ebx\n"
"	je	.L191\n"
".L170:\n"
"	movl	4(%edi), %esi\n"
"	movl	8(%edi), %eax\n"
"	movl	12(%edi), %edx\n"
"	cmpl	-12(%edi), %esi\n"
"	movl	(%edi), %ebp\n"
"	movl	%eax, 44(%esp)\n"
"	movl	%edx, 48(%esp)\n"
"	jle	.L192\n"
".L159:\n"
"	movl	%edi, %eax\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L126:\n"
"	movl	44(%esp), %ecx\n"
"	addl	$16, %edi\n"
"	movl	48(%esp), %edx\n"
"	cmpl	%edi, %ebx\n"
"	movl	%ebp, (%eax)\n"
"	movl	%esi, 4(%eax)\n"
"	movl	%ecx, 8(%eax)\n"
"	movl	%edx, 12(%eax)\n"
"	jne	.L170\n"
"	jmp	.L191\n"
".L124:\n"
"	movl	%ebx, %eax\n"
"	call	_ZSt16__insertion_sortIP5QueryEvT_S2_.constprop.1\n"
".L191:\n"
"	movl	nquery, %ebx\n"
"	movl	%ebx, 72(%esp)\n"
".L123:\n"
"	movl	nbee, %ebx\n"
"	movl	$meet, %edx\n"
"	xorl	%eax, %eax\n"
"	movl	$500, %ecx\n"
"	movl	%edx, %edi\n"
"	rep stosl\n"
"	movl	$0, 44(%esp)\n"
"	movl	%ebx, %esi\n"
"	testl	%esi, %esi\n"
"	movl	$0, 56(%esp)\n"
"	movl	$0, 60(%esp)\n"
"	jle	.L193\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L161:\n"
"	xorl	%eax, %eax\n"
"	movl	$1061109567, 48(%esp)\n"
"	movl	$1061109567, 52(%esp)\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L181:\n"
"	addl	$1, %eax\n"
"	cmpl	%esi, %eax\n"
"	je	.L131\n"
".L135:\n"
"	testl	%eax, %eax\n"
"	jle	.L181\n"
"	movl	dir(,%eax,8), %edx\n"
"	andl	dir+4(,%eax,8), %edx\n"
"	cmpl	$-1, %edx\n"
"	jne	.L181\n"
"	movl	dir-8(,%eax,8), %edx\n"
"	xorl	$1, %edx\n"
"	orl	dir-4(,%eax,8), %edx\n"
"	jne	.L181\n"
"	movl	pos(,%eax,8), %edi\n"
"	movl	pos+4(,%eax,8), %ebp\n"
"	subl	pos-8(,%eax,8), %edi\n"
"	sbbl	pos-4(,%eax,8), %ebp\n"
"	xorl	%ebx, %ebx\n"
"	movl	%ebp, %ecx\n"
"	shrl	$31, %ecx\n"
"	addl	%edi, %ecx\n"
"	adcl	%ebp, %ebx\n"
"	shrdl	$1, %ebx, %ecx\n"
"	sarl	%ebx\n"
"	cmpl	%ebx, 52(%esp)\n"
"	movl	%ebx, %edx\n"
"	jl	.L181\n"
"	jg	.L134\n"
"	cmpl	%ecx, 48(%esp)\n"
"	jbe	.L181\n"
".L134:\n"
"	addl	$1, %eax\n"
"	cmpl	%esi, %eax\n"
"	movl	%ecx, 48(%esp)\n"
"	movl	%edx, 52(%esp)\n"
"	jne	.L135\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L131:\n"
"	movl	72(%esp), %ebx\n"
"	cmpl	%ebx, 44(%esp)\n"
"	je	.L155\n"
".L195:\n"
"	movl	44(%esp), %eax\n"
"	sall	$4, %eax\n"
"	movl	query(%eax), %edx\n"
"	movl	query+4(%eax), %eax\n"
"	cmpl	%eax, 60(%esp)\n"
"	jg	.L137\n"
"	jl	.L164\n"
"	cmpl	%edx, 56(%esp)\n"
"	ja	.L137\n"
".L164:\n"
"	movl	56(%esp), %ecx\n"
"	movl	60(%esp), %ebx\n"
"	addl	48(%esp), %ecx\n"
"	adcl	52(%esp), %ebx\n"
"	movl	%ecx, 64(%esp)\n"
"	cmpl	%ebx, %eax\n"
"	movl	%ebx, 68(%esp)\n"
"	jg	.L137\n"
"	jl	.L165\n"
"	cmpl	%ecx, %edx\n"
"	jae	.L137\n"
".L165:\n"
"	movl	44(%esp), %ecx\n"
"	movl	%esi, 76(%esp)\n"
"	sall	$4, %ecx\n"
"	addl	$query+8, %ecx\n"
".L182:\n"
"	movl	(%ecx), %ebx\n"
"	movl	4(%ecx), %eax\n"
"	movl	-8(%ecx), %esi\n"
"	movl	-4(%ecx), %edi\n"
"	movl	dir+4(,%ebx,8), %edx\n"
"	leal	(%eax,%eax,2), %ebp\n"
"	movl	dir(,%ebx,8), %eax\n"
"	subl	56(%esp), %esi\n"
"	sbbl	60(%esp), %edi\n"
"	imull	%esi, %edx\n"
"	imull	%edi, %eax\n"
"	leal	(%eax,%edx), %edi\n"
"	movl	dir(,%ebx,8), %eax\n"
"	mull	%esi\n"
"	movl	%eax, 32(%esp)\n"
"	movl	32(%esp), %eax\n"
"	addl	%edi, %edx\n"
"	addl	pos(,%ebx,8), %eax\n"
"	movl	%edx, 36(%esp)\n"
"	movl	36(%esp), %edx\n"
"	adcl	pos+4(,%ebx,8), %edx\n"
"	movl	%eax, ans(,%ebp,4)\n"
"	movl	meet(,%ebx,4), %eax\n"
"	addl	$1, 44(%esp)\n"
"	movl	72(%esp), %ebx\n"
"	cmpl	%ebx, 44(%esp)\n"
"	movl	%edx, ans+4(,%ebp,4)\n"
"	movl	%eax, ans+8(,%ebp,4)\n"
"	je	.L155\n"
"	movl	12(%ecx), %eax\n"
"	cmpl	%eax, 60(%esp)\n"
"	movl	8(%ecx), %edx\n"
"	jg	.L190\n"
"	jl	.L166\n"
"	cmpl	%edx, 56(%esp)\n"
"	ja	.L190\n"
".L166:\n"
"	addl	$16, %ecx\n"
"	cmpl	68(%esp), %eax\n"
"	jg	.L190\n"
"	jl	.L182\n"
"	cmpl	64(%esp), %edx\n"
"	jb	.L182\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L190:\n"
"	movl	76(%esp), %esi\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L137:\n"
"	movl	52(%esp), %edx\n"
"	movl	48(%esp), %eax\n"
"	xorl	$1061109567, %edx\n"
"	xorl	$1061109567, %eax\n"
"	orl	%eax, %edx\n"
"	je	.L155\n"
"	xorl	%eax, %eax\n"
"	movl	$_ZZ5solvevE5hello, %edi\n"
"	movl	$125, %ecx\n"
"	testl	%esi, %esi\n"
"	rep stosl\n"
"	jle	.L147\n"
"	xorl	%eax, %eax\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L183:\n"
"	addl	$1, %eax\n"
"	cmpl	%esi, %eax\n"
"	je	.L194\n"
".L149:\n"
"	testl	%eax, %eax\n"
"	jle	.L183\n"
"	movl	dir(,%eax,8), %edx\n"
"	andl	dir+4(,%eax,8), %edx\n"
"	cmpl	$-1, %edx\n"
"	jne	.L183\n"
"	movl	dir-8(,%eax,8), %edx\n"
"	xorl	$1, %edx\n"
"	orl	dir-4(,%eax,8), %edx\n"
"	jne	.L183\n"
"	movl	pos(,%eax,8), %edi\n"
"	movl	pos+4(,%eax,8), %ebp\n"
"	subl	pos-8(,%eax,8), %edi\n"
"	sbbl	pos-4(,%eax,8), %ebp\n"
"	xorl	%ebx, %ebx\n"
"	movl	52(%esp), %edx\n"
"	movl	%ebp, %ecx\n"
"	shrl	$31, %ecx\n"
"	addl	%edi, %ecx\n"
"	adcl	%ebp, %ebx\n"
"	shrdl	$1, %ebx, %ecx\n"
"	xorl	48(%esp), %ecx\n"
"	sarl	%ebx\n"
"	xorl	%ebx, %edx\n"
"	orl	%ecx, %edx\n"
"	jne	.L183\n"
"	movb	$1, _ZZ5solvevE5hello(%eax)\n"
"	movb	$1, _ZZ5solvevE5hello-1(%eax)\n"
"	addl	$1, %eax\n"
"	cmpl	%esi, %eax\n"
"	jne	.L149\n"
".L194:\n"
"	movl	%esi, %ebp\n"
"	movl	52(%esp), %edi\n"
"	xorl	%ecx, %ecx\n"
"	movl	48(%esp), %esi\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L150:\n"
"	movl	dir(,%ecx,8), %ebx\n"
"	movl	dir+4(,%ecx,8), %eax\n"
"	imull	%edi, %ebx\n"
"	imull	%esi, %eax\n"
"	addl	%eax, %ebx\n"
"	movl	dir(,%ecx,8), %eax\n"
"	mull	%esi\n"
"	addl	%ebx, %edx\n"
"	movl	%eax, 64(%esp)\n"
"	movl	64(%esp), %eax\n"
"	addl	%eax, pos(,%ecx,8)\n"
"	movl	%edx, 68(%esp)\n"
"	movl	68(%esp), %edx\n"
"	adcl	%edx, pos+4(,%ecx,8)\n"
"	addl	$1, %ecx\n"
"	cmpl	%ebp, %ecx\n"
"	jne	.L150\n"
"	movl	%ebp, %esi\n"
"	xorl	%eax, %eax\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L152:\n"
"	cmpb	$0, _ZZ5solvevE5hello(%eax)\n"
"	je	.L151\n"
"	negl	dir(,%eax,8)\n"
"	adcl	$0, dir+4(,%eax,8)\n"
"	negl	dir+4(,%eax,8)\n"
"	addl	$1, meet(,%eax,4)\n"
".L151:\n"
"	addl	$1, %eax\n"
"	cmpl	%esi, %eax\n"
"	jne	.L152\n"
".L147:\n"
"	movl	48(%esp), %edx\n"
"	addl	%edx, 56(%esp)\n"
"	movl	52(%esp), %ecx\n"
"	adcl	%ecx, 60(%esp)\n"
"	testl	%esi, %esi\n"
"	jg	.L161\n"
".L193:\n"
"	movl	72(%esp), %ebx\n"
"	cmpl	%ebx, 44(%esp)\n"
"	movl	$1061109567, 48(%esp)\n"
"	movl	$1061109567, 52(%esp)\n"
"	jne	.L195\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L155:\n"
"	movl	72(%esp), %eax\n"
"	testl	%eax, %eax\n"
"	jle	.L116\n"
"	movl	$ans+8, %ebx\n"
"	xorl	%esi, %esi\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L154:\n"
"	movl	(%ebx), %eax\n"
"	xorl	%edx, %edx\n"
"	movl	%eax, 16(%esp)\n"
"	movl	-4(%ebx), %ebp\n"
"	movl	-8(%ebx), %edi\n"
"	movl	$.LC3, 4(%esp)\n"
"	movl	$1, (%esp)\n"
"	movl	%ebp, %eax\n"
"	shrl	$31, %eax\n"
"	addl	%edi, %eax\n"
"	adcl	%ebp, %edx\n"
"	addl	$1, %esi\n"
"	shrdl	$1, %edx, %eax\n"
"	addl	$12, %ebx\n"
"	sarl	%edx\n"
"	movl	%eax, 8(%esp)\n"
"	movl	%edx, 12(%esp)\n"
"	call	__printf_chk\n"
"	cmpl	%esi, nquery\n"
"	jg	.L154\n"
".L116:\n"
"	addl	$92, %esp\n"
"	.cfi_remember_state\n"
"	.cfi_def_cfa_offset 20\n"
"	popl	%ebx\n"
"	.cfi_def_cfa_offset 16\n"
"	.cfi_restore 3\n"
"	popl	%esi\n"
"	.cfi_def_cfa_offset 12\n"
"	.cfi_restore 6\n"
"	popl	%edi\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_restore 7\n"
"	popl	%ebp\n"
"	.cfi_def_cfa_offset 4\n"
"	.cfi_restore 5\n"
"	ret\n"
".L192:\n"
"	.cfi_restore_state\n"
"	jl	.L163\n"
"	cmpl	-16(%edi), %ebp\n"
"	.p2align 4,,2\n"
"	jae	.L159\n"
".L163:\n"
"	leal	-16(%edi), %eax\n"
"	movl	%edi, %edx\n"
"	.p2align 4,,3\n"
"	jmp	.L128\n"
".L197:\n"
"	cmpl	(%ecx), %ebp\n"
"	jae	.L126\n"
".L160:\n"
"	movl	%eax, %edx\n"
"	movl	%ecx, %eax\n"
".L128:\n"
"	movl	(%eax), %ecx\n"
"	movl	%ecx, (%edx)\n"
"	movl	4(%eax), %ecx\n"
"	movl	%ecx, 4(%edx)\n"
"	movl	8(%eax), %ecx\n"
"	movl	%ecx, 8(%edx)\n"
"	movl	12(%eax), %ecx\n"
"	movl	%ecx, 12(%edx)\n"
"	leal	-16(%eax), %ecx\n"
"	cmpl	4(%ecx), %esi\n"
"	jl	.L160\n"
"	jg	.L126\n"
"	jmp	.L197\n"
"	.cfi_endproc\n"
".LFE429:\n"
"	.size	_Z5solvev, .-_Z5solvev\n"
"	.section	.text.startup,\"ax\",@progbits\n"
"	.p2align 4,,15\n"
"	.globl	main\n"
"	.type	main, @function\n"
"main:\n"
".LFB430:\n"
"	.cfi_startproc\n"
"	pushl	%ebp\n"
"	.cfi_def_cfa_offset 8\n"
"	.cfi_offset 5, -8\n"
"	movl	%esp, %ebp\n"
"	.cfi_def_cfa_register 5\n"
"	andl	$-16, %esp\n"
"	subl	$32, %esp\n"
"	leal	28(%esp), %eax\n"
"	movl	%eax, 4(%esp)\n"
"	movl	$.LC0, (%esp)\n"
"	call	scanf\n"
"	jmp	.L203\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L204:\n"
"	call	_Z5solvev\n"
".L203:\n"
"	movl	28(%esp), %eax\n"
"	leal	-1(%eax), %edx\n"
"	testl	%eax, %eax\n"
"	movl	%edx, 28(%esp)\n"
"	jne	.L204\n"
"	xorl	%eax, %eax\n"
"	leave\n"
"	.cfi_restore 5\n"
"	.cfi_def_cfa 4, 4\n"
"	ret\n"
"	.cfi_endproc\n"
".LFE430:\n"
"	.size	main, .-main\n"
"	.p2align 4,,15\n"
"	.type	_GLOBAL__sub_I_nbee, @function\n"
"_GLOBAL__sub_I_nbee:\n"
".LFB462:\n"
"	.cfi_startproc\n"
"	movl	$ans, %eax\n"
"	.p2align 4,,7\n"
"	.p2align 3\n"
".L206:\n"
"	movl	$0, (%eax)\n"
"	movl	$0, 4(%eax)\n"
"	movl	$0, 8(%eax)\n"
"	addl	$12, %eax\n"
"	cmpl	$ans+12000, %eax\n"
"	jne	.L206\n"
"	rep\n"
"	ret\n"
"	.cfi_endproc\n"
".LFE462:\n"
"	.size	_GLOBAL__sub_I_nbee, .-_GLOBAL__sub_I_nbee\n"
"	.section	.ctors,\"aw\",@progbits\n"
"	.align 4\n"
"	.long	_GLOBAL__sub_I_nbee\n"
"	.globl	ans\n"
"	.bss\n"
"	.align 32\n"
"	.type	ans, @object\n"
"	.size	ans, 12000\n"
"ans:\n"
"	.zero	12000\n"
"	.globl	nquery\n"
"	.align 4\n"
"	.type	nquery, @object\n"
"	.size	nquery, 4\n"
"nquery:\n"
"	.zero	4\n"
"	.globl	query\n"
"	.align 32\n"
"	.type	query, @object\n"
"	.size	query, 16000\n"
"query:\n"
"	.zero	16000\n"
"	.globl	meet\n"
"	.align 32\n"
"	.type	meet, @object\n"
"	.size	meet, 2000\n"
"meet:\n"
"	.zero	2000\n"
"	.globl	dir\n"
"	.align 32\n"
"	.type	dir, @object\n"
"	.size	dir, 4000\n"
"dir:\n"
"	.zero	4000\n"
"	.globl	pos\n"
"	.align 32\n"
"	.type	pos, @object\n"
"	.size	pos, 4000\n"
"pos:\n"
"	.zero	4000\n"
"	.globl	nbee\n"
"	.align 4\n"
"	.type	nbee, @object\n"
"	.size	nbee, 4\n"
"nbee:\n"
"	.zero	4\n"
"	.local	_ZZ5solvevE5hello\n"
"	.comm	_ZZ5solvevE5hello,500,32\n"
"	.ident	\"GCC: (Ubuntu/Linaro 4.6.1-9ubuntu3) 4.6.1\"\n"
"	.section	.note.GNU-stack,\"\",@progbits\n"
);
