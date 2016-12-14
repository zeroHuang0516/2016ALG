1. 學號：b03901156
2. 姓名：黃于瑄
3. 使用之程式語言：< C++ >
4. 使用之編譯器：< GNU g++ >
5. 檔案壓縮方式: <zip>
6. 各檔案說明：
	 b03901156-p1/main/src : source files including sort.cpp, parser.cpp, parser.h
	 b03901156-p1/main/bin  : binary files including insertionSort, mergeSort, quickSort, heapSort 
	 b03901156-p1/main/Makefile : Makefile
	 b03901156-p1/main/report.doc : program report
	 b03901156-p1/main/readme.txt : the file explains how the program executes

7. 編譯方式說明：        	
	 請在main的目錄下，鍵入make all指令，即可完成編譯，
	 在main的目錄下同時產生insertionSort, mergeSort, quickSort, heapSort四個執行檔
	 如果要重新編譯，請先執行 make clean 再執行一次 make all
	
8. 執行、使用方式說明：
   主程式：
   編譯完成後，在main目錄下會產生insertionSort, mergeSort, quickSort, heapSort四個執行檔
   執行檔的命令格式為：
	./insertionSort <input_file_name> <output_file_name>
	./mergeSort <input_file_name> <output_file_name>
	./quickSort <input_file_name> <output_file_name>
	./heapSort <input_file_name> <output_file_name>

9. 執行結果說明 ：
	 程式執行後會在 console 輸出進行當前輸入資料排序所花費的時間
	 The execution spends ______ seconds.