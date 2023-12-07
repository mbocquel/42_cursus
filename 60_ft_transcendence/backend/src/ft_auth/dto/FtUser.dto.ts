import {
    IsEmail,
    IsNotEmpty,
    IsString,  
  } from 'class-validator';
  
  export class FtUser {
    @IsString()
    @IsNotEmpty()
    login: string;
    
    @IsString()
    @IsNotEmpty()
    username: string;
    
    @IsEmail()
    @IsNotEmpty()
    email: string;
  }