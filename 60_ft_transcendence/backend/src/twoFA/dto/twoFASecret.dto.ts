import {
    IsNotEmpty,
    IsString,  
  } from 'class-validator';
  
  export class twoFASecretDto {
    @IsString()
    @IsNotEmpty()
    login: string;

    @IsString()
    @IsNotEmpty()
    secret: string;
  }