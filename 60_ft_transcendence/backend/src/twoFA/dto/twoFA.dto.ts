import {
    IsNotEmpty,
    IsString,  
  } from 'class-validator';
  
  export class twoFADto {
    @IsString()
    @IsNotEmpty()
    token: string;
  }