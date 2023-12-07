import {
    IsNotEmpty,
    IsString,  
  } from 'class-validator';
  
  export class LoginDto {
    @IsString()
    @IsNotEmpty()
    login: string;
  }