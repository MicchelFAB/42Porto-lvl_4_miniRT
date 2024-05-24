/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:23:57 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/16 14:51:56 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ID 		"Multiple entries for id"
# define FILE_NF	"file not found"
# define INFO_SCENE "Scene description file is missing some required info"
# define RT_FILE	"is not a rt file"
# define LINE		"scene line split"

# define RESOL		"Invalid value(s) for Resolution"

# define A_RATIO	"Invalid value for Ambient Light ratio."
# define A_RGB		"Invalid value(s) for Ambient Light's RGB colour"

# define C_COORD	"Invalid value for Camera coordinates of the view point"
# define C_NORM		"Invalid value for Camera 3D normalized orientation vector"
# define C_FOV		"Invalid value for Camera FOV (horizontal field of view)"

# define L_COORD	"Invalid value coord of the light point"
# define L_RATIO	"Invalid value for Light's brightness ratio"
# define L_RGB		"Invalid value for Light's RGB colour"

# define SP_COORD	"Invalid value for Sphere's coordinates."
# define SP_DIAM	"Invalid value for Sphere's diameter."
# define SP_RGB		"Invalid value for Sphere's RGB colour."
# define SP_SPEC	"Invalid value for Sphere's specular colour."

# define PL_COORD	"Invalid value for Plane's coordinates."
# define PL_RGB		"Invalid value for Plane's RGB colour"

# define SQ_COORD	"Invalid value for Square's coordinates"
# define SQ_SIZE	"Invalid value for Square's side size"
# define SQ_RGB		"Invalid value for Square's RGB colour"

# define CY_COORD	"Invalid value for Cylinder's coordinates"
# define CY_NORM	"Invalid for Cylinder's 3D normalized orientation vector."
# define CY_DIAM	"Invalid value for Cylinder's diameter."
# define CY_HEIGHT	"Invalid value for Cylinder's height"
# define CY_RGB		"Invalid value for Cylinder's RGB colour"

# define CO_COORD	"Invalid value for CONE's coordinates"
# define CO_NORM	"Invalid value for CONE's 3D normalized orientation vector."
# define CO_DIAM	"Invalid value for CONE's diameter."
# define CO_HEIGHT	"Invalid value for CONE's height"
# define CO_RGB		"Invalid value for CONE's RGB colour"

# define CB_COORD	"Invalid value for cube's coordinates"
# define CB_NORM	"Invalid value for cube's 3D normalized orientation vector."
# define CB_SIZE	"Invalid value for cube's size."
# define CB_RGB		"Invalid value for cube's RGB colour"

# define TR_P1		"Invalid value for triangle's coordinates P1"
# define TR_P2		"Invalid value for triangle's coordinates P2"
# define TR_P3		"Invalid value for triangle's coordinates P3"
# define TR_COORD	"Invalid value for triangle's coordinates center"
# define TR_NORM	"Invalid for triangle's 3D normalized orientation vector."
# define TR_RGB		"Invalid value for triangle's RGB colour"

# define RGB_BONUS	"Invalid value for RGB parttern colour"

# define RF_SHIN	"Invalid value for shininess"
# define RF_REF		"Invalid value for shininess"

# define GL_TRANS	"Invalid value for transparency"
# define GL_REFLEC	"Invalid value for refractive_index"

#endif