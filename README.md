# Student Record Management System

This project is a simple **C-based Student Record Management System** that allows two types of users:

1. **Admin**
2. **Student**

Guest login has been removed as requested.

## Features

### **Admin**
- Add student records  
- View all student details  
- Search students  
- Modify existing student records  
- Delete records  
- Manage login credentials  

### **Student**
- View their own profile after login  
- Update limited personal information (if enabled in code)

## Files Used
- `students.txt` — Stores student information  
- `credentials.txt` — Stores admin & student login credentials  
- `studentrecordmanagment.c` — Main source code  
- `studentrecordmanagment_readonly.c` — Read‑only backup version  

## How to Compile
Use any C compiler such as GCC:

```bash
gcc studentrecordmanagment.c -o student_mgmt
```

Run the program:

```bash
./student_mgmt
```

## Login
During compilation, ensure that:
- The credential file contains correct username/password pairs.
- User roles must be either **admin** or **student**.

Example credentials in `credentials.txt`:
```
admin admin123 admin
harsha pass123 student
```

## Notes
- Make sure the data files are in the same directory as the compiled program.
- Text files are automatically created if missing.
- The system does not allow guest login (removed as requested).
- Input validations have been improved to avoid invalid login crashes.

## Author
Generated README for your student record management system.
