// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentDatabase {
    address public owner;

    struct Student {
        uint studentId;
        string name;
        uint age;
    }

    Student[] public students;
    mapping(uint => uint) private studentIdToIndex; // studentId -> index+1

    // Events
    event StudentAdded(uint studentId, string name, uint age);
    event PaymentReceived(address from, uint amount);

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can call this function.");
        _;
    }

    function addStudent(uint _studentId, string memory _name, uint _age) public onlyOwner {
        require(_studentId != 0, "Invalid student ID.");
        require(studentIdToIndex[_studentId] == 0, "Student with this ID already exists.");

        students.push(Student(_studentId, _name, _age));
        studentIdToIndex[_studentId] = students.length; // store index+1
        emit StudentAdded(_studentId, _name, _age);
    }

    function getStudent(uint _studentId) public view returns (uint, string memory, uint) {
        require(studentIdToIndex[_studentId] != 0, "Student not found.");
        uint index = studentIdToIndex[_studentId] - 1;
        Student memory student = students[index];
        return (student.studentId, student.name, student.age);
    }

    function getStudentCount() public view returns (uint) {
        return students.length;
    }

    fallback() external payable {
        emit PaymentReceived(msg.sender, msg.value);
    }

    receive() external payable {
        emit PaymentReceived(msg.sender, msg.value);
    }
}
