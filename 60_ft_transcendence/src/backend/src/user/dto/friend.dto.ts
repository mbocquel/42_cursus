import {
    IsEmail,
    IsNotEmpty,
    IsOptional,
    IsString,
    Matches,
	IsNumber,
	NotContains,
  } from 'class-validator';


  export class addFriendDto {

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	login:string;

	@NotContains(' ')
	@IsString()
	@IsNotEmpty()
	friendToAdd: string;
  }
