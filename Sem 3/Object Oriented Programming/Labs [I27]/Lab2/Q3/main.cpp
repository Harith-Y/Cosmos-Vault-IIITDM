cout << "Create Matrix 2:" << endl;
    m2.createMatrix();
    m2.displayMatrix();

    // Matrix addition
    cout << "\nMatrix Addition:" << endl;
    m3 = m1.addMatrix(m2);
    m3.displayMatrix();
    m3.freeMatrix();

    // Matrix subtraction
    cout << "\nMatrix Subtraction:" << endl;
    m3 = m1.subMatrix(m2);
    m3.displayMatrix();
    m3.freeMatrix();

    // Matrix multiplication
    cout << "\nMatrix Multiplication:" << endl;
    m3 = m1.mulMatrix(m2);
    m3.displayMatrix();
    m3.freeMatrix();

    m1.displayMatrix();

    cout << endl << "determinant of the given matrix is " << m1.detMatrix();

    m2 = m1.transMatrix();
    m3 = m1.invMatrix();

    // Free matrices
    m1.freeMatrix();
    m2.freeMatrix();

    return 0;
}