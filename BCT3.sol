// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {
    address payable public owner;

    event Deposited(address indexed from, uint256 amount);
    event Withdrawn(address indexed to, uint256 amount);

    modifier onlyOwner() {
        require(msg.sender == owner, "You are not the owner.");
        _;
    }

    constructor() {
        owner = payable(msg.sender);
    }

    // deposit funds to the contract
    function deposit() public payable {
        require(msg.value > 0, "Send some ETH");
        emit Deposited(msg.sender, msg.value);
    }

    // withdraw amount (in wei) to owner
    function withdraw(uint256 _amount) public onlyOwner {
        require(address(this).balance >= _amount, "Insufficient balance.");
        owner.transfer(_amount);
        emit Withdrawn(owner, _amount);
    }

    // get contract balance (owner-only)
    function getBalance() public view onlyOwner returns (uint256) {
        return address(this).balance;
    }
}
